// https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        int n = nums.size();

        if (n % 2 != 0)
        {
            return false;
        }

        if (k == 1)
        {
            return true;
        }

        vector<int> rem(k, 0);

        for (int i = 0; i < n; i++)
        {
            rem[nums[i] % k]++;
        }

        for (int i = 1; i < k / 2; i++)
        {
            if (rem[i] != rem[k - i])
            {
                return false;
            }
        }

        return k % 2 == 0 && rem[k / 2] % 2 == 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++)
            cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
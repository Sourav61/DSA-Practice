// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1/#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int setsBit(int n, int pos)
    {
        return ((n & (1 << pos)) != 0);
    }

    vector<int> singleNumber(vector<int> nums)
    {
        vector<int> ans;
        int xorSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xorSum = xorSum ^ nums[i];
        }

        int tempXor = xorSum;
        int setBit = 0;
        int pos = 0;
        while (setBit != 1)
        {
            setBit = xorSum & 1;
            pos++;
            xorSum = xorSum >> 1;
        }

        int newXor = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (setsBit(nums[i], pos - 1))
            {
                newXor = newXor ^ nums[i];
            }
        }

        ans.push_back(newXor);
        ans.push_back(tempXor ^ newXor);

        // cout << newXor << endl;
        // cout << (tempXor ^ newXor) << endl;

        sort(ans.begin(), ans.end());

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(2 * n + 2);
        for (int i = 0; i < 2 * n + 2; i++)
            cin >> v[i];
        Solution ob;
        vector<int> ans = ob.singleNumber(v);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends
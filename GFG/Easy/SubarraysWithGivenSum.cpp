// https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum2804/1

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int subArraySum(int nums[], int n, int k)
    {
        if (n == 0)
        {
            return 0;
        }

        unordered_map<int, int> mp;

        int currSum = 0, i = 0, count = 0;

        while (i < n)
        {
            currSum += nums[i];

            if (currSum == k)
            {
                count += 1;
            }

            if (mp.find(currSum - k) != mp.end())
            {
                count += mp[currSum - k];
            }

            mp[currSum] += 1;
            i++;
        }

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> sum;
        Solution ob;
        cout << ob.subArraySum(arr, n, sum);
        cout << '\n';
    }
    return 0;
}
// } Driver Code Ends
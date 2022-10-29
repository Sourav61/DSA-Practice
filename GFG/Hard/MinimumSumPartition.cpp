// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int dfs(int ind, int upperBound, int nums[], vector<vector<int>> &dp, int n)
    {
        if (ind > n - 1)
            return 0;

        if (dp[ind][upperBound] != -1)
            return dp[ind][upperBound];

        int notTaken = dfs(ind + 1, upperBound, nums, dp, n);

        int taken = -1e8;
        if (nums[ind] <= upperBound)
        {
            taken = nums[ind] + dfs(ind + 1, upperBound - nums[ind], nums, dp, n);
        }

        return dp[ind][upperBound] = max(notTaken, taken);
    }

    int minDifference(int arr[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += arr[i];

        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
        return abs(sum - 2 * dfs(0, sum / 2, arr, dp, n));
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends
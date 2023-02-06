// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find the maximum possible amount of money we can win.
class Solution
{
public:
    // long long f(int i,int j,int arr[],vector<vector<int>> &dp){
    //     if(i > j){
    //         return 0;
    //     }

    //     if(dp[i][j] != -1)
    //         return dp[i][j];

    //     long long maxi = 0;

    //     long long left = arr[i] + min(f(i+1,j-1,arr,dp),f(i+2,j,arr,dp));
    //     long long right = arr[j] + min(f(i,j-2,arr,dp), f(i+1,j-1,arr,dp));

    //     maxi = max(maxi, max(left, right));

    //     return dp[i][j] = maxi;
    // }

    long long f(int i, int j, int nums[], int player, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (player == 1)
        {
            return dp[i][j] = max(nums[i] + f(i + 1, j, nums, 2, dp), nums[j] + f(i, j - 1, nums, 2, dp));
        }
        else
        {
            return dp[i][j] = min(f(i + 1, j, nums, 1, dp), f(i, j - 1, nums, 1, dp));
        }
    }

    long long maximumAmount(int arr[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n - 1, arr, 1, dp);
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
        cout << ob.maximumAmount(a, n) << endl;
    }
    return 0;
}
// } Driver Code Endss
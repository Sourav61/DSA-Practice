// https://practice.geeksforgeeks.org/problems/7a33c749a79327b2889d420dd80342fff33aac6d/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // calculate the maximum sum with out adjacent

    int solve(int *arr, int ind, int n, vector<int> &dp)
    {
        if (ind >= n)
        {
            return 0;
        }

        if (dp[ind] != -1)
        {
            return dp[ind];
        }

        int ans = max(arr[ind] + solve(arr, ind + 2, n, dp), solve(arr, ind + 1, n, dp));

        return dp[ind] = ans;
    }

    int findMaxSum(int *arr, int n)
    {
        vector<int> dp(n, -1);
        return solve(arr, 0, n, dp);
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Endss
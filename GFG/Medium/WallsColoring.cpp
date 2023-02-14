// https://practice.geeksforgeeks.org/problems/51b266505221b97522b1d2c86ddad1868a54831b/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution
{
public:
    long long int sol(int prev, int idx, int &n, vector<vector<int>> &colors, vector<vector<long long int>> &dp)
    {
        if (idx == n)
        {
            return 0;
        }

        long long int take1 = INT_MAX, take2 = INT_MAX;

        if (dp[idx][prev] != -1)
        {
            return dp[idx][prev];
        }

        if (prev == 0)
        {
            take1 = colors[idx][1] + sol(1, idx + 1, n, colors, dp);
            take2 = colors[idx][2] + sol(2, idx + 1, n, colors, dp);
        }

        if (prev == 1)
        {
            take1 = colors[idx][0] + sol(0, idx + 1, n, colors, dp);
            take2 = colors[idx][2] + sol(2, idx + 1, n, colors, dp);
        }

        if (prev == 2)
        {
            take1 = colors[idx][1] + sol(1, idx + 1, n, colors, dp);
            take2 = colors[idx][0] + sol(0, idx + 1, n, colors, dp);
        }

        return dp[idx][prev] = min(take1, take2);
    }

    int minCost(vector<vector<int>> &colors, int N)
    {
        long long int mini = INT_MAX;
        vector<vector<long long int>> dp(N, vector<long long int>(4, -1));

        for (int i = 0; i < 3; i++)
        {
            mini = min(mini, sol(i, 0, N, colors, dp));
        }

        return mini;
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
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];

        Solution ob;
        cout << ob.minCost(colors, n) << endl;
    }
}
// } Driver Code Endss
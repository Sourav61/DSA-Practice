// https://practice.geeksforgeeks.org/problems/96161dfced02d544fc70c71d09b7a616fe726085/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int mod = (int)(1e9 + 7);

    int dfs(vector<vector<int>> &grid, int i, int j, int n, int m, vector<vector<int>> &dp)
    {
        if (i == n - 1 && j == m - 1)
        {
            return 1;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j] % mod;
        }

        int right = 0, down = 0;

        if (i + 1 < n && grid[i + 1][j] == 1)
        {
            right = dfs(grid, i + 1, j, n, m, dp);
        }

        if (j + 1 < m && grid[i][j + 1] == 1)
        {
            down = dfs(grid, i, j + 1, n, m, dp);
        }

        return dp[i][j] = (right + down) % mod;
    }

    int uniquePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        if (grid[0][0] == 0 || grid[n - 1][m - 1] == 0)
        {
            return 0;
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return dfs(grid, 0, 0, n, m, dp) % mod;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n, m, grid) << endl;
    }
    return 0;
}
// } Driver Code Ends
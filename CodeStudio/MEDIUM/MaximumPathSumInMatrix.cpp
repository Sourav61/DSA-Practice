// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?leftPanelTab=0

#include <bits/stdc++.h>

int f(int i, int j, int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (i > n - 1 || j < 0 || i < 0 || j > m - 1)
    {
        return -10000000;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == n - 1)
    {
        return mat[i][j];
    }

    int left = mat[i][j] + f(i + 1, j - 1, n, m, mat, dp);
    int down = mat[i][j] + f(i + 1, j, n, m, mat, dp);
    int right = mat[i][j] + f(i + 1, j + 1, n, m, mat, dp);

    return dp[i][j] = max(left, max(down, right));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    // int n = matrix.size();
    // int m = matrix[0].size();
    // int maxi = INT_MIN;
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // for (int j = 0; j < m; j++)
    // {
    //     int res = f(0, j, n, m, matrix, dp);
    //     maxi = max(maxi, res);
    // }

    // return maxi;

    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            int left = (j - 1) >= 0 ? matrix[i + 1][j - 1] : -10000000;
            int right = (j + 1) < m ? matrix[i + 1][j + 1] : -10000000;
            int down = matrix[i + 1][j];

            matrix[i][j] = matrix[i][j] + max(left, max(right, down));
        }
    }

    int ans = INT_MIN;

    for (int j = 0; j < m; j++)
    {
        ans = max(ans, matrix[0][j]);
    }
    return ans;
}
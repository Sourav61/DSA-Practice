// https://leetcode.com/problems/triangle/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // ===========================          Memoization Approach       ====================================

    // int solve(vector<vector<int>> &triangle, int n,int i,int row, vector<vector<int>> &dp){
    //     if(row == n-1){
    //         return triangle[row][i];
    //     }

    //     if(dp[i][row] != -1){
    //         return dp[i][row];
    //     }

    //     int bottom = triangle[row][i] + solve(triangle, n, i,row + 1,dp);
    //     int right = triangle[row][i] + solve(triangle, n, i+1,row + 1,dp);

    //     return dp[i][row] = min(bottom, right);
    // }

    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();

    //     vector<vector<int>> dp(n,vector<int> (n,-1));

    //     return solve(triangle, n, 0, 0,dp);
    // }

    // ===========================          Tabulation Approach       ====================================

    // int minimumTotal(vector<vector<int>> &triangle)
    // {
    //     int n = triangle.size();

    //     vector<vector<int>> dp(n, vector<int>(n, 100000));

    //     for (int row = 0; row < n; row++)
    //     {
    //         for (int i = 0; i <= row; i++)
    //         {
    //             if (i == 0 && row == 0)
    //             {
    //                 dp[row][i] = triangle[row][i];
    //                 continue;
    //             }
    //             int up = 0, left = 0;

    //             up = dp[row - 1][i];
    //             if (i == 0)
    //             {
    //                 left = INT_MAX;
    //             }
    //             else
    //             {
    //                 left = dp[row - 1][i - 1];
    //             }

    //             dp[row][i] = min(up, left) + triangle[row][i];
    //         }
    //     }

    //     int mini = INT_MAX;

    //     for (int i = 0; i < n; i++)
    //     {
    //         mini = min(mini, dp[n - 1][i]);
    //     }

    //     return mini;
    // }

    // Space-Optimization Approach

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        vector<int> prev(n, 100000);
        for (int row = 0; row < n; row++)
        {
            vector<int> cur(n, 100000);
            for (int j = 0; j <= row; j++)
            {
                if (j == 0 && row == 0)
                {
                    cur[j] = triangle[row][j];
                    continue;
                }

                int up = 0, left = 0;

                up = prev[j];
                if (j == 0)
                {
                    left = INT_MAX;
                }
                else
                {
                    left = prev[j - 1];
                }

                cur[j] = min(up, left) + triangle[row][j];
            }
            prev = cur;
        }

        int mini = INT_MAX;

        for (int j = 0; j < n; j++)
        {
            mini = min(mini, prev[j]);
        }

        return mini;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    cout << obj.minimumTotal(triangle);

    return 0;
}
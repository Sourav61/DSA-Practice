// https://leetcode.com/problems/minimum-path-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if ((i != 1 && j != 1) || (i == 1 && j == 1))
                {
                    dp[i][j] = grid[i - 1][j - 1] + min(dp[i][j - 1], dp[i - 1][j]);
                }
                else if (i == 1 || j == 1)
                {
                    dp[i][j] = grid[i - 1][j - 1] + max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> grid
    {
        {1, 3, 1}, {1, 5, 1}, { 4, 2, 1 }
    }

    cout << obj.minPathSum(grid);

    return 0;
}
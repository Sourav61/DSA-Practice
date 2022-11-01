// https://leetcode.com/problems/where-will-the-ball-fall/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> res;
    void dfs(vector<vector<int>> &grid, int i, int j, int n, int m, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            res.push_back(j);
            dp[i][j] = j;
            return;
        }

        if (dp[i][j] != 0)
        {
            res.push_back(dp[i][j]);
            return;
        }

        if ((j == 0 && grid[i][j] == -1) || (j == m - 1 && grid[i][j] == 1))
        {
            res.push_back(-1);
            dp[i][j] = -1;
            return;
        }

        if (j <= m - 2 && grid[i][j] + grid[i][j + 1] == 0 && grid[i][j] == 1)
        {
            res.push_back(-1);
            dp[i][j] = -1;
            return;
        }
        if (j > 0 && grid[i][j - 1] + grid[i][j] == 0 && grid[i][j] == -1)
        {
            res.push_back(-1);
            dp[i][j] = -1;
            return;
        }

        if (j < 0 || j >= m)
        {
            res.push_back(-1);
            dp[i][j] = -1;
            return;
        }

        if (grid[i][j] == 1)
        {
            dfs(grid, i + 1, j + 1, n, m, dp);
        }
        else if (grid[i][j] == -1)
        {
            dfs(grid, i + 1, j - 1, n, m, dp);
        }
    }

    vector<int> findBall(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 0; j < m; j++)
        {
            dfs(grid, 0, j, n, m, dp);
        }

        return res;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> grid{{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}};

    cout << obj.findBall(grid);

    return 0;
}
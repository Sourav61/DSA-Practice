// https://leetcode.com/problems/minimum-path-cost-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sol(int r, int c, int &n, int &m, vector<vector<int>> &grid, vector<vector<int>> &moveCost,
            vector<vector<int>> &dp)
    {
        if (r == n - 1)
        {
            return grid[r][c];
        }

        if (dp[r][c] != -1)
        {
            return dp[r][c];
        }

        int res = INT_MAX;

        for (int id = 0; id < m; id++)
        {
            res = min(res, grid[r][c] + moveCost[grid[r][c]][id] + sol(r + 1, id, n, m, grid, moveCost, dp));
        }

        return dp[r][c] = res;
    }

    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            ans = min(ans, sol(0, i, n, m, grid, moveCost, dp));
        }

        return ans;
    }
    // int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    // {
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minH;

    //     for (int j = 0; j < m; j++)
    //     {
    //         minH.push({grid[0][j], 0, j});
    //     }

    //     vector<vector<int>> vis(n, vector<int>(m, 1e9));

    //     while (!minH.empty())
    //     {
    //         auto curr = minH.top();
    //         minH.pop();

    //         auto cost = curr[0];
    //         auto row = curr[1];
    //         auto col = curr[2];

    //         if (row == n - 1)
    //         {
    //             return cost;
    //         }

    //         for (int c = 0; row < n - 1 && c < m; c++)
    //         {
    //             int newCost = cost + moveCost[grid[row][col]][c] + grid[row + 1][c];
    //             if (newCost < vis[row + 1][c])
    //             {
    //                 vis[row + 1][c] = newCost;
    //                 minH.push({newCost, row + 1, c});
    //             }
    //         }
    //     }

    //     return -1;
    // }
};

int main()
{

    Solution obj;

    vector<vector<int>> grid = {{5, 3}, {4, 0}, {2, 1}};

    vector<vector<int>> moveCost = {{9, 8}, {1, 5}, {10, 12}, {18, 6}, {2, 4}, {14, 3}};

    cout << obj.minPathCost(grid, moveCost);

    return 0;
}
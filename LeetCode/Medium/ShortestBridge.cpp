// https://leetcode.com/problems/shortest-bridge/description/

#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, queue<vector<int>> &q)
    {
        vis[row][col] = 1;
        q.push({row, col, 0});

        for (int k = 0; k < 4; k++)
        {
            int i = row + dx[k];
            int j = col + dy[k];

            if (i >= 0 && i < n && j >= 0 && j < n && !vis[i][j] && grid[i][j] == 1)
            {
                dfs(i, j, vis, grid, n, q);
            }
        }
    }

    int shortestBridge(vector<vector<int>> &grid)
    {
        queue<vector<int>> q;

        int n = grid.size();

        vector<vector<int>> vis(n, vector<int>(n, 0));

        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            if (flag == true)
            {
                break;
            }
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(i, j, vis, grid, n, q);
                    flag = true;
                    break;
                }
            }
        }

        while (!q.empty())
        {
            auto row = q.front()[0];
            auto col = q.front()[1];
            auto cost = q.front()[2];

            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int i = row + dx[k];
                int j = col + dy[k];

                if (i >= 0 && i < n && j >= 0 && j < n && !vis[i][j])
                {
                    if (grid[i][j] == 0)
                    {
                        vis[i][j] = 1;
                        grid[i][j] = 1;
                        q.push({i, j, cost + 1});
                    }
                    else
                    {
                        return cost;
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> grid = {{1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}};

    cout << obj.shortestBridge(grid);

    return 0;
}
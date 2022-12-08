// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        queue<pair<pair<int, int>, int>> q;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

        q.push({{0, 0}, k});

        vis[0][0][k] = 1;

        int dis = 0;

        while (!q.empty())
        {
            int sz = q.size();

            while (sz-- > 0)
            {
                auto curr = q.front();
                q.pop();

                int row = curr.first.first;
                int col = curr.first.second;
                int obs = curr.second;

                if (row == n - 1 && col == m - 1)
                    return dis;

                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + dx[i];
                    int ncol = col + dy[i];

                    if (nrow < n && ncol < m && nrow >= 0 && ncol >= 0)
                    {
                        if (grid[nrow][ncol] == 0 && vis[nrow][ncol][obs] == 0)
                        {
                            vis[nrow][ncol][obs] = 1;
                            q.push({{nrow, ncol}, obs});
                        }
                        else if (grid[nrow][ncol] == 1 && obs > 0 && vis[nrow][ncol][obs - 1] == 0)
                        {
                            vis[nrow][ncol][obs - 1] = 1;
                            q.push({{nrow, ncol}, obs - 1});
                        }
                    }
                }
            }

            dis++;
        }

        return -1;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0}};
    int k = 1;

    cout << obj.shortestPath(grid, k);

    return 0;
}
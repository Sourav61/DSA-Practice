// https://leetcode.com/problems/number-of-enclaves/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int vis[n][m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1))
                {
                    if (grid[i][j] == 1)
                    {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                    else
                    {
                        vis[i][j] = 0;
                    }
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> grid
    {
        {0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, { 0, 0, 0, 0 }
    }

    cout << obj.numEnclaves(grid);

    return 0;
}
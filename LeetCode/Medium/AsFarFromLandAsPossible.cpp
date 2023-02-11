// https://leetcode.com/problems/as-far-from-land-as-possible/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                }
            }
        }

        int res = -1;

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int row = x + dx[i];
                int col = y + dy[i];
                if (row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0)
                {
                    grid[row][col] = grid[x][y] + 1;
                    res = max(res, grid[row][col]);
                    q.push({row, col});
                }
            }
        }

        return res == -1 ? res : res - 1;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};

    cout << obj.maxDistance(grid) << endl;

    return 0;
}
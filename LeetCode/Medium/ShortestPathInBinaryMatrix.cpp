// https://leetcode.com/problems/shortest-path-in-binary-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
        {
            return -1;
        }

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        queue<pair<int, int>> q;

        q.push({0, 0});
        dist[0][0] = 0;

        int delrow[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int delcol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();

            int row = temp.first;
            int col = temp.second;

            if (row == n - 1 && col == m - 1)
            {
                return dist[row][col] + 1;
            }

            for (int i = 0; i < 8; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 && dist[nrow][ncol] == 1e9)
                {
                    dist[nrow][ncol] = dist[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return -1;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> grid{{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};

    cout << obj.shortestPathBinaryMatrix(grid);

    return 0;
}
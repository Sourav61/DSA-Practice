// https://leetcode.com/problems/check-knight-tour-configuration/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidGrid(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] != 0)
        {
            return false;
        }

        int row = 0, col = 0, tar = grid[row][col];

        int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

        while (grid[row][col] != (n * n - 1))
        {
            tar = grid[row][col];

            for (int k = 0; k < 8; k++)
            {
                int i = row + dx[k];
                int j = col + dy[k];
                if (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == (tar + 1))
                {
                    row = i, col = j;
                    break;
                }
            }

            if (grid[row][col] != tar + 1)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> grid = {{0, 11, 16, 5, 20}, {17, 4, 19, 10, 15}, {12, 1, 8, 21, 6}, {3, 18, 23, 14, 9}, {24, 13, 2, 7, 22}};

    cout << obj.checkValidGrid(grid);

    return 0;
}
// https://leetcode.com/contest/biweekly-contest-92/problems/difference-between-ones-and-zeros-in-row-and-column/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> res;

        vector<int> rows;

        vector<int> cols;
        for (int i = 0; i < n; i++)
        {
            int cntOnes = 0;
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    cntOnes++;
                }
            }

            rows.push_back(cntOnes);
        }

        for (int j = 0; j < m; j++)
        {
            int cntOnes = 0;
            for (int i = 0; i < n; i++)
            {
                if (grid[i][j] == 1)
                {
                    cntOnes++;
                }
            }

            cols.push_back(cntOnes);
        }

        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j < m; j++)
            {
                temp.push_back(2 * (rows[i] + cols[j]) - (n + m));
            }
            res.push_back(temp);
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> grid = {{0, 1, 1}, {1, 0, 1}, {0, 0, 1}};

    vector<vector<int>> res = obj.onesMinusZeros(grid);

    for (auto &v : res)
    {
        for (auto &x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
// https://leetcode.com/contest/weekly-contest-323/problems/delete-greatest-value-in-each-row/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sort(grid[i].begin(), grid[i].end(), greater<int>());
        }

        for (int j = 0; j < m; j++)
        {
            int maxi = 0;
            for (int i = 0; i < n; i++)
            {
                maxi = max(grid[i][j], maxi);
            }
            sum += maxi;
        }

        return sum;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> grid = {{1, 2, 4}, {3, 3, 1}};

    cout << obj.deleteGreatestValue(grid);

    return 0;
}
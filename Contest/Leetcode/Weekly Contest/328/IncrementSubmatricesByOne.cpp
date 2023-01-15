// https://leetcode.com/problems/increment-submatrices-by-one/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> temp(n, vector<int>(n, 0));

        for (auto &x : queries)
        {
            int row1 = x[0];
            int col1 = x[1];
            int row2 = x[2];
            int col2 = x[3];

            temp[row1][col1]++;
            if (col2 + 1 < n)
            {
                temp[row1][col2 + 1]--;
            }

            if (row2 + 1 < n)
            {
                temp[row2 + 1][col1]--;
            }

            if (row2 + 1 < n && col2 + 1 < n)
            {
                temp[row2 + 1][col2 + 1]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                temp[i][j] += temp[i][j - 1];
            }
        }

        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                temp[j][i] += temp[j - 1][i];
            }
        }

        return temp;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> queries = {{1, 1, 2, 2}, {0, 0, 1, 1}};

    vector<vector<int>> res = obj.rangeAddQueries(3, queries);

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
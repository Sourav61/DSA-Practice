// https://leetcode.com/problems/spiral-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> res;

        int left = 0, right = m - 1, up = 0, down = n - 1;

        while (res.size() < (n * m))
        {
            for (int j = left; j <= right; j++)
            {
                res.push_back(matrix[up][j]);
            }

            for (int i = up + 1; i <= down; i++)
            {
                res.push_back(matrix[i][right]);
            }

            if (up != down)
            {
                for (int j = right - 1; j >= left; j--)
                {
                    res.push_back(matrix[down][j]);
                }
            }

            if (left != right)
            {
                for (int i = down - 1; i > up; i--)
                {
                    res.push_back(matrix[i][left]);
                }
            }

            left++;
            right--;

            up++;
            down--;
        }

        return res;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> matrix
    {
        {1, 2, 3}, {4, 5, 6}, { 7, 8, 9 }
    }

    cout << obj.spiralOrder(matrix);

    return 0;
}
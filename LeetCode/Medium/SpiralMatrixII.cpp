// https://leetcode.com/problems/spiral-matrix-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n));

        int left = 0, right = n - 1, up = 0, down = n - 1;

        int ele = 1;

        while (ele <= n * n)
        {
            for (int j = left; j <= right; j++)
            {
                matrix[up][j] = ele;
                ele++;
            }

            for (int i = up + 1; i <= down; i++)
            {
                matrix[i][right] = ele;
                ele++;
            }

            if (up != down)
            {
                for (int j = right - 1; j >= left; j--)
                {
                    matrix[down][j] = ele;
                    ele++;
                }
            }

            if (left != right)
            {
                for (int i = down - 1; i > up; i--)
                {
                    matrix[i][left] = ele;
                    ele++;
                }
            }

            left++;
            right--;

            up++;
            down--;
        }

        return matrix;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> ans = obj.generateMatrix(3);

    for (auto v : ans)
    {
        for (auto x : v)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int r = 0, c = m - 1;

        while (r < n && c >= 0)
        {
            if (matrix[r][c] == target)
            {
                return 1;
            }
            else if (matrix[r][c] > target)
            {
                c--;
            }
            else
            {
                r++;
            }
        }

        return 0;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> matrix{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};

    int target = 5;

    cout << obj.searchMatrix(matrix, target);

    return 0;
}
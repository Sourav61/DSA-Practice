// https://leetcode.com/problems/minimum-falling-path-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int N = matrix.size();
        for (int i = N - 2; i >= 0; i--)
        {
            for (int j = 0; j < N; j++)
            {
                int a = (j - 1) >= 0 ? matrix[i + 1][j - 1] : 1e9;
                int b = (j + 1) < N ? matrix[i + 1][j + 1] : 1e9;
                int c = matrix[i + 1][j];

                matrix[i][j] = matrix[i][j] + min(a, min(b, c));
            }
        }

        int ans = INT_MAX;

        for (int j = 0; j < N; j++)
        {
            ans = min(ans, matrix[0][j]);
        }
        return ans;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> matrix{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};

    cout << obj.minFallingPathSum(matrix);

    return 0;
}
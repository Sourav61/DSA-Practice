// https://leetcode.com/problems/maximal-square/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
        {
            return 0;
        }
        int m = matrix[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int largest = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    if (largest < dp[i][j])
                    {
                        largest = dp[i][j];
                    }
                }
            }
        }

        return largest * largest;
    }
};

int main()
{
    Solution obj;

    vector<vector<char>> matrix{{"1", "0", "1", "0", "0"}, {"1", "0", "1", "1", "1"}, {"1", "1", "1", "1", "1"}, {"1", "0", "0", "1", "0"}};

    cout << obj.maximalSquare(matrix);

    return 0;
}
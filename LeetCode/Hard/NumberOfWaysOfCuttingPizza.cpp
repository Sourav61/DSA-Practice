// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int dp[51][51][11];
    int mod = (int)(1e9 + 7);

    long long int count(int r, int c, int cuts, int &n, int &m, vector<vector<int>> &apples)
    {
        if (dp[r][c][cuts] != -1)
        {
            return dp[r][c][cuts];
        }

        if (cuts == 0)
        {
            return dp[r][c][cuts] = (apples[r][c] > 0 ? 1 : 0);
        }

        long long int rowSum = 0, colSum = 0;

        for (int i = r + 1; i < n; i++)
        {
            if (apples[r][c] - apples[i][c] > 0 && apples[i][c] >= cuts)
            {
                rowSum = (rowSum + count(i, c, cuts - 1, n, m, apples)) % mod;
            }
        }

        for (int j = c + 1; j < m; j++)
        {
            if (apples[r][c] - apples[r][j] > 0 && apples[r][c] >= cuts)
            {
                colSum = (colSum + count(r, j, cuts - 1, n, m, apples)) % mod;
            }
        }

        return dp[r][c][cuts] = rowSum + colSum;
    }

    int ways(vector<string> &pizza, int k)
    {
        int n = pizza.size();
        int m = pizza[0].size();

        memset(dp, -1, sizeof(dp));

        vector<vector<int>> apples(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                apples[i][j] = apples[i + 1][j] + apples[i][j + 1] - apples[i + 1][j + 1] + (pizza[i][j] == 'A');
            }
        }

        long long int ans = count(0, 0, k - 1, n, m, apples);

        return (int)ans;
    }
};

int main()
{

    Solution obj;

    vector<string> pizza = {"A..", "AAA", "..."};

    cout << obj.ways(pizza, 3);

    return 0;
}
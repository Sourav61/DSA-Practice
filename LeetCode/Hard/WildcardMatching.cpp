// https://leetcode.com/problems/wildcard-matching/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool f(int i, int j, string &pattern, string &text, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
        {
            return true;
        }
        if (i < 0 && j >= 0)
        {
            return false;
        }
        if (j < 0 && i >= 0)
        {
            for (int x = 0; x <= i; x++)
            {
                if (pattern[x] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (pattern[i] == text[j] || pattern[i] == '?')
        {
            return dp[i][j] = f(i - 1, j - 1, pattern, text, dp);
        }

        if (pattern[i] == '*')
        {
            return dp[i][j] = f(i - 1, j, pattern, text, dp) | f(i, j - 1, pattern, text, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p)
    {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, p, s, dp);
    }
};

int main()
{

    Solution obj;

    cout << obj.isMatch("a*ab", "baaabab");

    return 0;
}
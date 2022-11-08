// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lcs(string &s, string &t)
    {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        for (int j = 0; j <= n; j++)
        {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][n];
    }

    int minInsertions(string s)
    {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        return n - lcs(s, t);
    }
};

int main()
{
    Solution obj;

    cout << obj.minInsertions("mbadm");

    return 0;
}
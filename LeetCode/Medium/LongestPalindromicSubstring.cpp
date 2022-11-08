// https://leetcode.com/problems/longest-palindromic-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        int row = 0, col = 0, mxi = 0, mxj = 0;

        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                if (g == 0)
                {
                    dp[i][j] = true;
                }
                else if (g == 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                else
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }

                if (!dp[i][j])
                {
                    continue;
                }

                if (j - i > mxj - mxi && dp[i][j])
                {
                    mxj = j;
                    mxi = i;
                }
            }
        }

        return s.substr(mxi, mxj - mxi + 1);
    }
};

int main()
{
    Solution obj;

    cout << obj.longestPalindrome("babad");

    return 0;
}
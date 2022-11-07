// https://leetcode.com/problems/longest-palindromic-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.length();

        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        for (int j = 0; j <= n; j++)
        {
            prev[j] = 0;
        }

        int maxLen = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    cur[j] = 1 + prev[j - 1];
                }
                else
                {
                    cur[j] = max(prev[j], cur[j - 1]);
                }

                maxLen = max(maxLen, cur[j]);
            }

            prev = cur;
        }

        return maxLen;
    }
};

int main()
{
    Solution obj;

    cout << obj.longestPalindromeSubseq("bbbab");

    return 0;
}
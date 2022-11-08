// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string longestPalin(string s)
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

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalin(S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete this method*/
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

    int wildCard(string pattern, string str)
    {
        int n = pattern.size();
        int m = str.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, pattern, str, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends
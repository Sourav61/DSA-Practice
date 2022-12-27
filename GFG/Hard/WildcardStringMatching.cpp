// https://practice.geeksforgeeks.org/problems/wildcard-string-matching1126/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
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

    bool match(string wild, string pattern)
    {
        int n = wild.size();
        int m = pattern.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, wild, pattern, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string wild, pattern;
        cin >> wild >> pattern;

        Solution ob;
        if (ob.match(wild, pattern))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
// } Driver Code Ends
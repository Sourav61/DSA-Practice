// https://practice.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (j < 0)
        {
            return 1;
        }

        if (i < 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == t[j])
        {
            return dp[i][j] = (f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp));
        }

        return dp[i][j] = f(i - 1, j, s, t, dp);
    }

    int countWays(string S1, string S2)
    {
        int n = S1.length();
        int m = S2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n - 1, m - 1, S1, S2, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S1, S2;
        cin >> S1;
        cin >> S2;

        Solution ob;
        cout << ob.countWays(S1, S2) << endl;
    }
    return 0;
}
// } Driver Code Ends
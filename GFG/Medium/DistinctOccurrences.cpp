// https://practice.geeksforgeeks.org/problems/distinct-occurrences/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    int mod = (int)(1e9 + 7);

private:
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
            return dp[i][j] = (f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp)) % mod;
        }

        return dp[i][j] = f(i - 1, j, s, t, dp) % mod;
    }

public:
    int subsequenceCount(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n - 1, m - 1, s, t, dp) % mod;
    }
};

//{ Driver Code Starts.

//  Driver code to check above method
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        string tt;
        cin >> s;
        cin >> tt;

        Solution ob;
        cout << ob.subsequenceCount(s, tt) << endl;
    }
}
// } Driver Code Ends
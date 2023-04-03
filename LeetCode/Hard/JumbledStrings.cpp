// https://practice.geeksforgeeks.org/problems/jumbled-strings0431/1

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int mod = (int)(1e9 + 7);
    int sol(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (j == t.size())
        {
            return 1;
        }

        if (i == s.size())
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == t[j])
        {
            return dp[i][j] = (sol(i + 1, j, s, t, dp) % mod + sol(i + 1, j + 1, s, t, dp) % mod) % mod;
        }

        return dp[i][j] = sol(i + 1, j, s, t, dp) % mod;
    }

    int TotalWays(string str)
    {
        string temp = "GEEKS";
        vector<vector<int>> dp(str.size(), vector<int>(temp.size(), -1));

        return sol(0, 0, str, temp, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.TotalWays(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
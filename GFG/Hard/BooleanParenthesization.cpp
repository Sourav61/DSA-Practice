// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define ll long long

class Solution
{
public:
    ll f(int i, int j, string &S, bool isTrue, vector<vector<vector<ll>>> &dp)
    {
        if (i > j)
        {
            return 0;
        }

        if (i == j)
        {
            if (isTrue)
            {
                return S[i] == 'T';
            }
            else
            {
                return S[i] == 'F';
            }
        }

        if (dp[i][j][isTrue] != -1)
        {
            return dp[i][j][isTrue];
        }

        ll res = 0;

        for (int ind = i + 1; ind <= j - 1; ind += 2)
        {
            ll lT = f(i, ind - 1, S, true, dp);
            ll lF = f(i, ind - 1, S, false, dp);
            ll rT = f(ind + 1, j, S, true, dp);
            ll rF = f(ind + 1, j, S, false, dp);

            if (S[ind] == '&')
            {
                if (isTrue)
                    res = res + (lT * rT);
                else
                    res = res + (lF * rF) + (lT * rF) + (lF * rT);
            }
            else if (S[ind] == '|')
            {
                if (isTrue)
                {
                    res = res + (lT * rT) + (lT * rF) + (lF * rT);
                }
                else
                {
                    res = res + (lF * rF);
                }
            }
            else if (S[ind] == '^')
            {
                if (isTrue)
                    res = res + (lF * rT) + (lT * rF);
                else
                {
                    res = res + (lT * rT) + (lF * rF);
                }
            }
        }

        return dp[i][j][isTrue] = res % 1003;
    }

    int countWays(int n, string S)
    {
        vector<vector<vector<ll>>> dp(n,
                                      vector<vector<ll>>(n,
                                                         vector<ll>(2, -1)));

        return f(0, n - 1, S, true, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        string S;
        cin >> S;

        Solution ob;
        cout << ob.countWays(N, S) << "\n";
    }
    return 0;
}
// } Driver Code Ends
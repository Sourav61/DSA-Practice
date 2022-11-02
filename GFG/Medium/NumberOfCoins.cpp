// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int minCoins(int coins[], int M, int V)
    {
        vector<vector<int>> dp(M, vector<int>(V + 1, 0));

        for (int T = 0; T <= V; T++)
        {
            if (T % coins[0] == 0)
            {
                dp[0][T] = T / coins[0];
            }
            else
            {
                dp[0][T] = 1e9;
            }
        }

        for (int ind = 1; ind < M; ind++)
        {
            for (int T = 0; T <= V; T++)
            {
                int notTake = dp[ind - 1][T];
                int take = INT_MAX;
                if (coins[ind] <= T)
                {
                    take = 1 + dp[ind][T - coins[ind]];
                }

                dp[ind][T] = min(take, notTake);
            }
        }

        int res = dp[M - 1][V];

        if (res >= 1e9)
        {
            return -1;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, m, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/aa0000a5f710ce8d41366b714341eef644ec7b82/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int mod = 1000000007;
    int f(int node, int steps, vector<vector<int>> &dp)
    {
        if (steps == 0 && node == 0)
        {
            return 1;
        }
        if (steps == 0 && node != 0)
        {
            return 0;
        }

        int ans = 0;

        if (node == 0)
        {
            if (dp[0][steps] != -1)
            {
                return dp[0][steps];
            }

            ans = (ans + f(1, steps - 1, dp)) % mod;
            ans = (ans + f(2, steps - 1, dp)) % mod;
            ans = (ans + f(3, steps - 1, dp)) % mod;

            return dp[0][steps] = ans;
        }
        else if (node == 1)
        {
            if (dp[1][steps] != -1)
            {
                return dp[1][steps];
            }
            ans = (ans + f(0, steps - 1, dp)) % mod;
            ans = (ans + f(2, steps - 1, dp)) % mod;
            ans = (ans + f(3, steps - 1, dp)) % mod;

            return dp[1][steps] = ans;
        }
        else if (node == 2)
        {
            if (dp[2][steps] != -1)
            {
                return dp[2][steps];
            }

            ans = (ans + f(0, steps - 1, dp)) % mod;
            ans = (ans + f(1, steps - 1, dp)) % mod;
            ans = (ans + f(3, steps - 1, dp)) % mod;

            return dp[2][steps] = ans;
        }
        else if (node == 3)
        {
            if (dp[3][steps] != -1)
            {
                return dp[3][steps];
            }

            ans = (ans + f(0, steps - 1, dp)) % mod;
            ans = (ans + f(1, steps - 1, dp)) % mod;
            ans = (ans + f(2, steps - 1, dp)) % mod;

            return dp[3][steps] = ans;
        }

        return ans;
    }

    int countPaths(int N)
    {
        if (N == 0)
        {
            return 0;
        }

        vector<vector<int>> dp(4, vector<int>(N + 1));
        dp[0][0] = 1;

        for (int steps = 1; steps <= N; steps++)
        {
            for (int node = 0; node < 4; node++)
            {
                dp[node][steps] = (dp[node][steps] + dp[(node + 1) % 4][steps - 1]) % mod;
                dp[node][steps] = (dp[node][steps] + dp[(node + 2) % 4][steps - 1]) % mod;
                dp[node][steps] = (dp[node][steps] + dp[(node + 3) % 4][steps - 1]) % mod;
            }
        }

        return dp[0][N];
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

        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0;
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right3011/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long int numberOfPaths(int m, int n)
    {
        vector<vector<long long int>> dp(m + 1, vector<long long int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == 1 || j == 1 && i != j)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000007;
                }
            }
        }

        return dp[m][n];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout << ob.numberOfPaths(m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
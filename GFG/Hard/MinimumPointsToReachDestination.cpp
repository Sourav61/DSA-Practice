// https://practice.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int minPoints(vector<vector<int>> points, int M, int N)
    {
        vector<vector<int>> dp(M, vector<int>(N, 0));

        for (int i = M - 1; i >= 0; --i)
        {
            for (int j = N - 1; j >= 0; --j)
            {
                if (i == M - 1 && j == N - 1)
                {
                    dp[i][j] = min(0, points[i][j]);
                }
                else if (i == M - 1)
                {
                    dp[i][j] = min(0, points[i][j] + dp[i][j + 1]);
                }
                else if (j == N - 1)
                {
                    dp[i][j] = min(0, points[i][j] + dp[i + 1][j]);
                }
                else
                {
                    dp[i][j] = min(0, points[i][j] + max(dp[i][j + 1], dp[i + 1][j]));
                }
            }
        }

        return abs(dp[0][0]) + 1;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        Solution ob;
        cout << ob.minPoints(a, m, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends
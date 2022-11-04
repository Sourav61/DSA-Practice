// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat)
    {
        if (n == 0)
        {
            return 0;
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int largest = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (mat[i - 1][j - 1] == 1)
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    if (largest < dp[i][j])
                    {
                        largest = dp[i][j];
                    }
                }
            }
        }

        return largest;
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
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends
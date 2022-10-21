// https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    // Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        vector<vector<long long int>> dp(a + 1, vector<long long int>(b + 1, 0));

        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
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

        return dp[a][b];
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking dimensions of the matrix
        int a, b;
        cin >> a >> b;
        Solution ob;
        // calling NumberOfPath() function
        cout << ob.NumberOfPath(a, b) << endl;
    }
}

// } Driver Code Ends
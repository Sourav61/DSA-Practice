// https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    pair<string, int> f(int i, int j, int arr[], vector<vector<pair<string, int>>> &dp)
    {
        if (i == j)
        {
            string temp = "";
            temp += 'A' + i - 1;
            return {temp, 0};
        }

        if (dp[i][j].second != -1)
        {
            return dp[i][j];
        }

        int mini = 1e9;
        string minStr = "";
        for (int k = i; k < j; k++)
        {
            auto left = f(i, k, arr, dp);
            auto right = f(k + 1, j, arr, dp);
            int steps = arr[i - 1] * arr[k] * arr[j] + left.second + right.second;
            string s = "";
            s = "(" + left.first + right.first + ")";
            if (mini > steps)
            {
                mini = steps;
                minStr = s;
            }
        }

        dp[i][j] = {minStr, mini};
        return dp[i][j];
    }

    string matrixChainOrder(int p[], int N)
    {
        vector<vector<pair<string, int>>> dp(N, vector<pair<string, int>>(N, {"", -1}));

        return f(1, N - 1, p, dp).first;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i];

        Solution ob;
        cout << ob.matrixChainOrder(p, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends
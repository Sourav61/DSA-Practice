// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int f(int i, int j, int n, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        if (i > n - 1 || j < 0 || i < 0 || j > n - 1)
        {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == n - 1)
        {
            return mat[i][j];
        }

        int left = mat[i][j] + f(i + 1, j - 1, n, mat, dp);
        int down = mat[i][j] + f(i + 1, j, n, mat, dp);
        int right = mat[i][j] + f(i + 1, j + 1, n, mat, dp);

        return dp[i][j] = max(left, max(down, right));
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // int maxi = INT_MIN;
        // vector<vector<int>> dp(N, vector<int>(N, -1));
        // for (int j = 0; j < N; j++)
        // {
        //     int res = f(0, j, N, Matrix, dp);
        //     maxi = max(maxi, res);
        // }

        // return maxi;

        for (int i = N - 2; i >= 0; i--)
        {
            for (int j = 0; j < N; j++)
            {
                int left = (j - 1) >= 0 ? Matrix[i + 1][j - 1] : 0;
                int right = (j + 1) < N ? Matrix[i + 1][j + 1] : 0;
                int down = Matrix[i + 1][j];

                Matrix[i][j] = Matrix[i][j] + max(left, max(right, down));
            }
        }

        int ans = 0;

        for (int j = 0; j < N; j++)
        {
            ans = max(ans, Matrix[0][j]);
        }
        return ans;
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
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
}
// } Driver Code Ends
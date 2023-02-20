// https://practice.geeksforgeeks.org/problems/234ca3b438298fb04befd5abe7fbd98c006d4884/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>> &mat, vector<vector<bool>> &vis, int i, int j, int r, int c)
    {
        if (i < 0 || j < 0 || i >= r || j >= c || vis[i][j])
            return;

        vis[i][j] = true;

        for (int k = 0; k < 4; k++)
        {
            int row = i + dx[k];
            int col = j + dy[k];

            if (row >= 0 && col >= 0 && row < r && col < c && !vis[row][col] && mat[row][col] >= mat[i][j])
            {
                dfs(mat, vis, row, col, r, c);
            }
        }
    }

    int water_flow(vector<vector<int>> &mat, int N, int M)
    {
        // Write your code here.
        vector<vector<bool>> indian(N, vector<bool>(M, 0));
        vector<vector<bool>> arabian(N, vector<bool>(M, 0));

        int ans = 0;

        for (int i = 0; i < M; i++)
        {
            dfs(mat, indian, 0, i, N, M);
            dfs(mat, arabian, N - 1, i, N, M);
        }

        for (int i = 0; i < N; i++)
        {
            dfs(mat, indian, i, 0, N, M);
            dfs(mat, arabian, i, M - 1, N, M);
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (indian[i][j] == 1 && arabian[i][j] == 1)
                    ans++;
            }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
    }
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/number-of-islands/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
            {
                dfs(nrow, ncol, grid, vis);
            }
        }
    }

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        vector<int> res;

        vector<vector<int>> grid(n, vector<int>(m, 0));

        for (auto x : operators)
        {
            int row = x[0];
            int col = x[1];

            grid[row][col] = 1;

            int ans = 0;
            vector<vector<int>> vis(n, vector<int>(m, 0));

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (vis[i][j] == 0 && grid[i][j] == 1)
                    {
                        dfs(i, j, grid, vis);
                        ans++;
                    }
                }
            }

            res.push_back(ans);
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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> a;

        for (int i = 0; i < k; i++)
        {
            vector<int> temp;
            for (int j = 0; j < 2; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.numOfIslands(n, m, a);

        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/shortest-path-by-removing-k-walls/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k)
    {
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        queue<pair<pair<int, int>, int>> q;

        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

        q.push({{0, 0}, k});

        vis[0][0][k] = 1;

        int dis = 0;

        while (!q.empty())
        {
            int sz = q.size();

            while (sz-- > 0)
            {
                auto curr = q.front();
                q.pop();

                int row = curr.first.first;
                int col = curr.first.second;
                int obs = curr.second;

                if (row == n - 1 && col == m - 1)
                    return dis;

                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + dx[i];
                    int ncol = col + dy[i];

                    if (nrow < n && ncol < m && nrow >= 0 && ncol >= 0)
                    {
                        if (mat[nrow][ncol] == 0 && vis[nrow][ncol][obs] == 0)
                        {
                            vis[nrow][ncol][obs] = 1;
                            q.push({{nrow, ncol}, obs});
                        }
                        else if (mat[nrow][ncol] == 1 && obs > 0 && vis[nrow][ncol][obs - 1] == 0)
                        {
                            vis[nrow][ncol][obs - 1] = 1;
                            q.push({{nrow, ncol}, obs - 1});
                        }
                    }
                }
            }

            dis++;
        }

        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, x;

        cin >> n >> m >> k;
        vector<vector<int>> mat;

        for (int i = 0; i < n; i++)
        {
            vector<int> row;
            for (int j = 0; j < m; j++)
            {
                cin >> x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout << ob.shotestPath(mat, n, m, k);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
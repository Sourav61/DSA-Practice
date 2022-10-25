// https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    typedef pair<int, pair<int, int>> pipii;
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        dist[0][0] = grid[0][0];

        priority_queue<pipii, vector<pipii>, greater<pipii>> minH;

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        minH.push({dist[0][0], {0, 0}});

        while (!minH.empty())
        {
            auto temp = minH.top();
            minH.pop();

            int dis = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;

            if (row == n - 1 && col == n - 1)
                break;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    dist[nrow][ncol] >= dist[row][col] + grid[nrow][ncol])
                {
                    dist[nrow][ncol] = grid[nrow][ncol] + dist[row][col];
                    minH.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }

        return dist[n - 1][n - 1];
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.minimumCostPath(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
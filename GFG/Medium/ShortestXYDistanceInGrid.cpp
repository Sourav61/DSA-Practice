// https://practice.geeksforgeeks.org/problems/7366ce450d84b55391fc787a681c4d60de359e72/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int shortestXYDist(vector<vector<char>> grid, int n, int m)
    {
        vector<vector<int>> dis(n, vector<int>(m, 1e5));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'X')
                {
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        int dist = 0;
        while (!q.empty())
        {
            int sz = q.size();

            while (sz--)
            {
                auto row = q.front().first;
                auto col = q.front().second;

                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int i = row + dx[k];
                    int j = col + dy[k];

                    if (i >= 0 && i < n && j >= 0 && j < m)
                    {
                        if (grid[i][j] == 'Y')
                        {
                            return dist + 1;
                        }

                        if (dis[i][j] > (dis[row][col] + 1))
                        {
                            dis[i][j] = dis[row][col] + 1;
                            q.push({i, j});
                        }
                    }
                }
            }

            dist++;
        }

        return dist;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++)
        {
            vector<char> col;
            for (int i = 0; i < M; i++)
            {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends
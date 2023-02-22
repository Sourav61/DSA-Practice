// https://practice.geeksforgeeks.org/problems/2145720aebf8ea0b07f76b17217b3353a0fbea7f/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minIteration(int N, int M, int x, int y)
    {
        // vector<vector<int>> grid(N, vector<int>(M, 0));
        // grid[x - 1][y - 1] = 1;

        // queue<pair<int, int>> q;

        // q.push({x - 1, y - 1});

        // int dx[4] = {-1, 0, 1, 0};
        // int dy[4] = {0, 1, 0, -1};

        // int level = 0;

        // while (!q.empty())
        // {
        //     int sz = q.size();
        //     while (sz--)
        //     {
        //         auto curr = q.front();
        //         q.pop();

        //         int row = curr.first, col = curr.second;

        //         for (int k = 0; k < 4; k++)
        //         {
        //             int i = row + dx[k], j = col + dy[k];

        //             if (i < N && i >= 0 && j < M && j >= 0 && grid[i][j] == 0)
        //             {
        //                 grid[i][j] = 1;
        //                 q.push({i, j});
        //             }
        //         }
        //     }
        //     level++;
        // }

        // return level - 1;

        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                ans = max(ans, abs(x - i) + abs(y - j));
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
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;

        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0;
}
// } Driver Code Ends
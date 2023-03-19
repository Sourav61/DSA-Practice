// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KP, vector<int> &TP, int n)
    {
        vector<vector<int>> grid(n, vector<int>(n, 0));

        queue<pair<int, int>> q;

        q.push({KP[0] - 1, KP[1] - 1});

        grid[KP[0] - 1][KP[1] - 1] = -1;

        int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

        int steps = 0;

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto row = q.front().first;
                auto col = q.front().second;

                q.pop();

                if (row == TP[0] - 1 && col == TP[1] - 1)
                {
                    return steps;
                }

                for (int k = 0; k < 8; k++)
                {
                    int i = row + dx[k];
                    int j = col + dy[k];

                    if (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] != -1)
                    {
                        q.push({i, j});
                        grid[i][j] = -1;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
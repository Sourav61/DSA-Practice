// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int node, int par, vector<int> adj[], int n, vector<bool> &hasApple)
    {
        int time = 0;

        for (auto &x : adj[node])
        {
            if (x != par)
            {
                int sub = dfs(x, node, adj, n, hasApple);
                time += sub;
            }
        }

        if (adj[node].size() == 1 and node != 0)
        {
            time += 2 * hasApple[node];
        }
        else if (node != 0)
        {
            if (time != 0 or hasApple[node])
            {
                time += 2;
            }
        }

        return time;
    }

    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<int> adj[n];

        for (auto &x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        return dfs(0, 0, adj, n, hasApple);
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};

    vector<bool> hasApple = {false, false, true, false, true, true, false};

    cout << obj.minTime(7, edges, hasApple);

    return 0;
}
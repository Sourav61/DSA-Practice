// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis)
    {
        vis[node] = 1;

        for (auto &x : adj[node])
        {
            if (!vis[x.first])
            {
                dfs(x.first, adj, vis);
            }
        }
    }

    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<int> vis(n + 1, 0);
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &x : roads)
        {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }

        dfs(1, adj, vis);

        int res = INT_MAX;

        if (!vis[1] || !vis[n])
        {
            return res;
        }

        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                for (int j = 0; j < adj[i].size(); j++)
                {
                    res = min(res, adj[i][j].second);
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};

    cout << obj.minScore(4, roads);

    return 0;
}
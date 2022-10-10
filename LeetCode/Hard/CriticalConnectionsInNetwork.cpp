// https://leetcode.com/problems/critical-connections-in-a-network/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> tin;
    vector<int> low;
    vector<int> vis;
    vector<vector<int>> graph;
    vector<vector<int>> ans;
    void dfs(int node, int parent, int timer)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto &x : graph[node])
        {
            if (x == parent)
            {
                continue;
            }
            if (!vis[x])
            {
                dfs(x, node, timer);
                low[node] = min(low[node], low[x]);
                if (low[x] > tin[node])
                {
                    ans.push_back({node, x});
                }
            }
            else
            {
                low[node] = min(low[node], tin[x]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        graph.resize(n);
        vis.resize(n, 0);
        low.resize(n, -1);
        tin.resize(n, -1);
        int timer = 0;
        for (auto &x : connections)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, i, timer);
            }
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};

    vector<vector<int>> res = obj.criticalConnections(4, connections);

    for (auto v : res)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
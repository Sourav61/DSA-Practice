// https://leetcode.com/problems/find-eventual-safe-states/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &pathVis, vector<int> &check)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for (auto x : graph[node])
        {
            if (!vis[x])
            {
                if (dfs(x, graph, vis, pathVis, check) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if (pathVis[x])
            {
                check[node] = 0;
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;

        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);

        vector<int> safeNodes;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, graph, vis, pathVis, check);
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
            {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> graph{
        {1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

    vector<int> res = obj.eventualSafeNodes(graph);

    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
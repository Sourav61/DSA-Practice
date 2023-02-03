// https://leetcode.com/problems/longest-cycle-in-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int res = -1;
    void dfs(int node, int N, vector<int> &Edge, vector<bool> &vis, vector<bool> &pathVis)
    {
        vis[node] = true;
        pathVis[node] = true;

        if (Edge[node] != -1)
        {
            int adj = Edge[node];
            if (!vis[adj])
            {
                dfs(adj, N, Edge, vis, pathVis);
            }
            if (vis[adj] && pathVis[adj])
            {
                int curr = adj;
                int len = 0;
                do
                {
                    len++;
                    curr = Edge[curr];
                } while (curr != adj);
                res = max(res, len);
            }
        }

        pathVis[node] = false;
    }

    int longestCycle(vector<int> &edges)
    {
        int N = edges.size();
        vector<bool> vis(N, 0), pathVis(N, 0);

        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                dfs(i, N, edges, vis, pathVis);
            }
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> edges = {3, 3, 4, 2, 3};

    cout << obj.longestCycle(edges);

    return 0;
}
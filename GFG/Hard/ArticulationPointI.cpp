// https://practice.geeksforgeeks.org/problems/articulation-point-1/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void dfs(int node, int parent, vector<int> &vis, vector<int> tin, vector<int> low, int timer, vector<int> adj[], vector<int> &isArticulation)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;

        for (auto x : adj[node])
        {
            if (x == parent)
            {
                continue;
            }
            if (!vis[x])
            {
                dfs(x, node, vis, tin, low, timer, adj, isArticulation);
                low[node] = min(low[node], low[x]);
                if (low[x] >= tin[node] && parent != -1)
                {
                    isArticulation[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[x]);
            }
        }

        if (parent == -1 && child > 1)
        {
            isArticulation[node] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<int> res;

        vector<int> tin(V, -1);
        vector<int> low(V, -1);
        vector<int> vis(V, 0);

        vector<int> isArticulation(V, 0);
        int timer = 0;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, tin, low, timer, adj, isArticulation);
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (isArticulation[i] == 1)
            {
                res.push_back(i);
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
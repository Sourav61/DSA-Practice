// https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(int node, vector<int> adj[], int c, int d, vector<int> &vis)
    {
        vis[node] = true;

        for (auto x : adj[node])
        {
            if (!vis[x] && (node != c || x != d))
            {
                dfs(node, adj, c, d, vis);
            }
        }
    }

    // Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        vector<int> vis(V, false);

        dfs(c, adj, c, d, vis);

        return !vis[d];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/1a4b617b70f0142a5c2b454e6fbe1b9a69ce7861/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &vertex, int &edge)
    {
        vis[node] = true;
        vertex++;
        edge += adj[node].size();

        for (auto &x : adj[node])
        {
            if (vis[x] == false)
            {
                dfs(x, adj, vis, vertex, edge);
            }
        }
    }

    int findNumberOfGoodComponent(int V, vector<vector<int>> &adj)
    {
        vector<int> vis(V + 1, false);

        int res = 0, vertex = 0, edge = 0;
        ;

        for (int i = 1; i <= V; i++)
        {
            if (vis[i] == false)
            {
                vertex = 0, edge = 0;
                dfs(i, adj, vis, vertex, edge);
                if (edge / 2 == (vertex * (vertex - 1) / 2))
                {
                    res++;
                }
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++)
        {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends
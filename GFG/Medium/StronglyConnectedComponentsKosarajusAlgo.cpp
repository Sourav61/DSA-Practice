// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;

        for (auto x : adj[node])
        {
            if (!vis[x])
            {
                dfs(x, st, vis, adj);
            }
        }

        st.push(node);
    }

    void revDfs(int node, vector<int> &vis, vector<int> transpose[])
    {
        vis[node] = 1;

        for (auto x : transpose[node])
        {
            if (!vis[x])
            {
                revDfs(x, vis, transpose);
            }
        }
    }

    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        int count = 0;
        stack<int> st;
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, st, vis, adj);
            }
        }

        vector<int> transpose[V];

        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto x : adj[i])
            {
                transpose[x].push_back(i);
            }
        }

        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                count++;
                revDfs(node, vis, transpose);
            }
        }

        return count;
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

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
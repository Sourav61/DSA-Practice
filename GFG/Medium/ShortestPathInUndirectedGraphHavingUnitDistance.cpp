// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
private:
    void topoSort(int node, vector<int> adj[], vector<int> vis, stack<int> &st)
    {
        vis[node] = 1;

        for (auto x : adj[node])
        {
            if (!vis[x])
            {
                topoSort(x, adj, vis, st);
            }
        }

        st.push(node);
    }

public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> adj[N];

        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(N, 0);
        stack<int> st;

        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                topoSort(i, adj, vis, st);
            }
        }

        vector<int> dist(N);

        for (int i = 0; i < N; i++)
        {
            dist[i] = 1e9;
        }

        dist[src] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto x : adj[node])
            {
                if (dist[node] + 1 < dist[x])
                {
                    dist[x] = dist[node] + 1;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 2; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
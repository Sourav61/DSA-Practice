// https://practice.geeksforgeeks.org/problems/e7d81a082cda6bd1e959d943197aa3bc21b88bdb/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> dijkstra(int a, int n, vector<pair<int, int>> adj[])
    {
        vector<int> dist(n + 1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[a] = 0;
        pq.push({0, a});

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int dis = curr.first;
            int node = curr.second;

            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;
                if (dist[v] > dist[node] + wt)
                {
                    dist[v] = dist[node] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[n + 1];
        vector<vector<int>> curved;

        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            int cwt = edges[i][3];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});

            curved.push_back({u, v, cwt});
            curved.push_back({v, u, cwt});
        }
        vector<int> dist1 = dijkstra(a, n, adj);
        vector<int> dist2 = dijkstra(b, n, adj);

        int ans = dist2[a];

        for (auto &x : curved)
        {
            int u = x[0];
            int v = x[1];
            int cwt = x[2];

            ans = min(ans, dist1[u] + cwt + dist2[v]);
        }

        if (ans >= 1e9)
            return -1;

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b;
        cin >> n >> m;
        cin >> a >> b;

        vector<vector<int>> edges;

        for (int i = 0; i < m; i++)
        {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            edges.push_back({u, v, x, y});
        }

        Solution ob;
        cout << ob.shortestPath(n, m, a, b, edges) << endl;
    }
    return 0;
}
// } Driver Code Ends
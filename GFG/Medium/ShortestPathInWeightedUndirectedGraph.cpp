// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    typedef pair<int, int> pii;
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[n + 1];

        for (auto x : edges)
        {
            adj[x][0].push_back({x[1], x[2]});
            adj[x][1].push_back({x[0], x[2]});
        }

        priority_queue<pii, vector<pii>, greater<pii>> minH;

        vector<int> dist(n + 1, 1e9), parent(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        dist[1] = 0;

        while (!minH.empty())
        {
            auto temp = minH.top();
            int node = temp.first;
            int dist = temp.second;

            minH.pop();

            for (auto x : adj[node])
            {
                int adjNode = x.first;
                int edgeWt = x.second;

                if (dist + edgeWt <= dist[adjNode])
                {
                    dist[adjNode] = dist + edgeWt;
                    pq.push({adjNode, dist[adjNode]});
                    parent[adjNode] = node;
                }
            }
        }

        if (dist[n] == 1e9)
        {
            return {-1};
        }

        vector<int> res;
        int node = n;

        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        res.push_back(1);
        reverse(res.begin(), res.end());

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    // your code goes here
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
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
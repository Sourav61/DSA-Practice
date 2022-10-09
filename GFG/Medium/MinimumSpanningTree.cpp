// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    typedef pair<int, int> pii;
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);

        priority_queue<pii, vector<pii>, greater<pii>> minH;

        key[0] = 0;
        minH.push({0, 0});

        while (!minH.empty())
        {
            int u = minH.top().second;
            minH.pop();

            mst[u] = true;

            for (auto x : adj[u])
            {
                int v = x[0];
                int wt = x[1];

                if (mst[v] == false && wt < key[v])
                {
                    key[v] = wt;
                    minH.push({key[v], v});
                }
            }
        }

        int sum = 0;

        for (int i = 0; i < V; i++)
        {
            sum += key[i];
        }

        return sum;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
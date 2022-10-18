// https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=/number-of-ways-to-arrive-at-destination

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> adj[n];

        for (auto x : roads)
        {
            int u = x[0];
            int v = x[1];
            int dist = x[2];

            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }

        vector<int> dist(n, 1e9), ways(n, 0);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;

        minH.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        int mod = (int)(1e9 + 7);

        while (!minH.empty())
        {
            int dis = minH.top().first;
            int node = minH.top().second;

            minH.pop();

            for (auto x : adj[node])
            {
                int adjNode = x.first;
                int edgeWt = x.second;

                if (dis + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWt;
                    minH.push({dis + edgeWt, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (dis + edgeWt == dist[adjNode])
                {
                    ways[adjNode] = (ways[node] + ways[adjNode]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends

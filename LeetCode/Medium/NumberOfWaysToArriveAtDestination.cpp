// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, long long int>> adj[n];

        for (auto x : roads)
        {
            int u = x[0];
            int v = x[1];
            long long int dist = x[2];

            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }

        vector<long long int> dist(n, 1e18), ways(n, 0);

        priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> minH;

        minH.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        int mod = (int)(1e9 + 7);

        while (!minH.empty())
        {
            long long int dis = minH.top().first;
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

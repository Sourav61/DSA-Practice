// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];

        for (auto x : flights)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }

        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();

            int stops = temp.first;
            int node = temp.second.first;
            int cost = temp.second.second;

            if (stops > k)
                continue;

            for (auto x : adj[node])
            {
                int adjNode = x.first;
                int edgeWt = x.second;

                if (cost + edgeWt < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = cost + edgeWt;
                    q.push({stops + 1, {adjNode, cost + edgeWt}});
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};

int main()
{

    Solution obj;

    int n = 4;
    vector<vector<int>> flights{{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int src = 0;
    int dst = 3;
    int k = 1;

    cout << obj.findCheapestPrice(n, flights, src, dst, k);

    return 0;
}
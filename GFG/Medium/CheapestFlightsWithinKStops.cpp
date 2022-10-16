// https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
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

            if (stops > K)
                continue;

            for (auto x : adj[node])
            {
                int adjNode = x.first;
                int edgeWt = x.second;

                if (cost + edgeWt < dist[adjNode] && stops <= K)
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

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int edge;
        cin >> edge;
        vector<vector<int>> flights;

        for (int i = 0; i < edge; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }

        int src, dst, k;
        cin >> src >> dst >> k;
        Solution obj;
        cout << obj.CheapestFLight(n, flights, src, dst, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends
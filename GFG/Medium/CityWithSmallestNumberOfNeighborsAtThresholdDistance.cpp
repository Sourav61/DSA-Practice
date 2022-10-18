// https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1?page=1&category[]=Disjoint%20Set&sortBy=submissions

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    // int findCity(int n, int m, vector<vector<int>> &edges,
    //              int distanceThreshold)
    // {
    //     vector<vector<int>> dp(n, vector<int>(n, 1e9));
    //     for (int i = 0; i < n; i++)
    //     {
    //         dp[i][i] = 0;
    //     }

    //     for (auto x : edges)
    //     {
    //         int src = x[0];
    //         int dest = x[1];
    //         int cost = x[2];

    //         dp[src][dest] = cost;
    //         dp[dest][src] = cost;
    //     }

    //     for (int k = 0; k < n; k++)
    //     {
    //         for (int i = 0; i < n; i++)
    //         {
    //             for (int j = 0; j < n; j++)
    //             {
    //                 if (dp[i][k] + dp[k][j] < dp[i][j])
    //                 {
    //                     dp[i][j] = dp[i][k] + dp[k][j];
    //                 }
    //             }
    //         }
    //     }

    //     int mini = INT_MAX, res = -1;

    //     for (int i = n - 1; i >= 0; i--)
    //     {
    //         int cnt = 0;
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (i == j)
    //                 continue;

    //             if (dp[i][j] <= distanceThreshold)
    //                 cnt++;
    //         }

    //         if (cnt < mini)
    //         {
    //             mini = cnt;
    //             res = i;
    //         }
    //     }
    //     return res;
    // }

    int djikstra(vector<vector<pair<int, int>>> &adj, int n, int src, int dT)
    {
        vector<int> dist(n, 1e9);

        dist[src] = 0;

        set<pair<int, int>> s;
        s.insert({0, src});

        while (!s.empty())
        {
            pair<int, int> temp = *(s.begin());
            int node = temp.second;

            s.erase(s.begin());

            for (auto x : adj[node])
            {
                int adjNode = x.first;
                int edgeWt = x.second;

                if (dist[node] + edgeWt < dist[adjNode] && dist[node] != 1e9)
                {
                    if (dist[adjNode] != 1e9)
                        s.erase(s.find({dist[adjNode], adjNode}));

                    dist[adjNode] = dist[node] + edgeWt;

                    s.insert({dist[adjNode], adjNode});
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (i == src)
                continue;

            if (dist[i] <= dT)
            {
                ans++;
            }
        }

        return ans;
    }

    int findCity(int n, int m, vector<vector<int>> &edges,
                 int distanceThreshold)
    {
        vector<vector<pair<int, int>>> adj(n);

        for (auto x : edges)
        {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }

        int max_city = 0, res = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int result = djikstra(adj, n, i, distanceThreshold);

            if (result < res)
            {
                res = result;
                max_city = i;
            }
            else if (result == res)
            {
                max_city = max(i, max_city);
            }
        }

        return max_city;
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
        vector<vector<int>> adj;
        // n--;
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

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends
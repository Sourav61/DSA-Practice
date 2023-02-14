// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/

#include <bitsstdc++.h>
using namespace std;

class Solution
{
public:
    // long long dfs(int node, vector<int> adj[], vector<int> &vis, int n, int seats, long long &res)
    // {
    //     vis[node] = true;

    //     long long cnt = 1;

    //     for (auto &x : adj[node])
    //     {
    //         if (!vis[x])
    //         {
    //             cnt += dfs(x, adj, vis, n, seats, res);
    //         }
    //     }

    //     long long temp = cnt / seats;
    //     if (cnt % seats)
    //     {
    //         temp++;
    //     }

    //     if (node != 0)
    //     {
    //         res += temp;
    //     }

    //     return cnt;
    // }

    // long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    // {
    //     if (roads.size() == 0)
    //     {
    //         return 0;
    //     }

    //     long long res = 0;
    //     int n = roads.size();
    //     vector<int> adj[n + 1];

    //     for (auto &x : roads)
    //     {
    //         adj[x[0]].push_back(x[1]);
    //         adj[x[1]].push_back(x[0]);
    //     }

    //     vector<int> vis(n + 1, 0);

    //     dfs(0, adj, vis, n, seats, res);

    //     return res;
    // }

    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        int n = roads.size();

        vector<int> adj[n + 1];
        vector<int> degree(n + 1, 0), peers(n + 1, 1);

        peers[0] = 0;

        for (auto &x : roads)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);

            degree[x[0]]++;
            degree[x[1]]++;
        }

        queue<int> q;
        long long fuel = 0;

        for (int i = 1; i < n + 1; i++)
        {
            if (degree[i] == 1)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int sz = q.size();

            while (sz--)
            {
                auto node = q.front();
                q.pop();

                if (node == 0)
                {
                    break;
                }

                fuel += peers[node] / seats;
                if (peers[node] % seats)
                {
                    fuel++;
                }

                degree[node] = 0;

                for (auto &x : adj[node])
                {
                    peers[x] += peers[node];
                    degree[x]--;

                    if (degree[x] == 1)
                    {
                        q.push(x);
                    }
                }
            }
        }

        return fuel;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> roads = {{0, 1}, {0, 2}, {0, 3}};

    cout << obj.minimumFuelCost(roads, 5);

    return 0;
}
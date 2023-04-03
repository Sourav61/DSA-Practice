// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<int> adj[n + 1];

        for (auto &x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        long long total = 0;
        vector<int> vis(n, 0);

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                q.push(i);
                long long temp = 0;
                while (!q.empty())
                {
                    auto curr = q.front();
                    q.pop();
                    vis[curr] = 1;
                    temp++;

                    for (int x : adj[curr])
                    {
                        if (!vis[x])
                        {
                            q.push(x);
                            vis[x] = 1;
                        }
                    }
                }
                total += (temp * (n - temp));
            }
        }

        return total / 2;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};

    cout << obj.countPairs(3, edges);

    return 0;
}
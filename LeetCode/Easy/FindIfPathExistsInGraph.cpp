// https://leetcode.com/problems/find-if-path-exists-in-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        unordered_map<int, vector<int>> mp;

        vector<int> adj[n];

        for (auto &x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int> vis(n, 0);

        queue<int> q;
        q.push(source);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            if (curr == destination)
            {
                return true;
            }

            vis[curr] = 1;

            for (auto &x : adj[curr])
            {
                if (vis[x] == 0)
                {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};

    cout << obj.validPath(3, edges, 0, 2);

    return 0;
}
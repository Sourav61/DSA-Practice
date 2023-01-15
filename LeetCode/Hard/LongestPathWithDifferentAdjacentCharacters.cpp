// https://leetcode.com/problems/longest-path-with-different-adjacent-characters/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxi = 1;
    int dist[100007];
    void dfs(int node, string &s, vector<int> adj[])
    {
        dist[node] = 1;
        for (auto &x : adj[node])
        {
            dfs(x, s, adj);
            if (x != node && s[x] != s[node])
            {
                maxi = max(maxi, dist[node] + dist[x]);
                dist[node] = max(dist[node], dist[x] + 1);
            }
        }
    }

    int longestPath(vector<int> &parent, string s)
    {
        int n = parent.size();
        vector<int> adj[n + 1];

        for (int i = 1; i < n; i++)
        {
            adj[parent[i]].push_back(i);
        }

        dfs(0, s, adj);

        return maxi;
    }
};

int main()
{

    Solution obj;
    vector<int> parent = {-1, 0, 0, 1, 1, 2};

    cout << obj.longestPath(parent, "abacbe");

    return 0;
}
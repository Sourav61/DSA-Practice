// https://practice.geeksforgeeks.org/problems/count-the-paths4332/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int cnt = 0;

    void dfs(int node, int dest, vector<int> adj[])
    {
        if (node == dest)
        {
            cnt++;
            return;
        }

        for (auto &x : adj[node])
        {
            dfs(x, dest, adj);
        }
    }

    int possible_paths(vector<vector<int>> edges, int n, int s, int d)
    {
        vector<int> adj[n];
        for (auto &x : edges)
        {
            adj[x[0]].push_back(x[1]);
        }

        dfs(s, d, adj);

        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, s, d;
        cin >> n >> m >> s >> d;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        int ans = obj.possible_paths(edges, n, s, d);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
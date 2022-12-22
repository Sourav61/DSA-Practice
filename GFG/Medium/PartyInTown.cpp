// https://practice.geeksforgeeks.org/problems/party-in-town3951/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxd = 0;

    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int curr)
    {
        vis[node] = 1;
        maxd = max(maxd, curr);

        for (auto &x : adj[node])
        {
            if (vis[x] != 1)
            {
                dfs(x, adj, vis, curr + 1);
            }
        }
    }

    int partyHouse(int N, vector<vector<int>> &adj)
    {
        int ans = INT_MAX;

        for (int i = 1; i <= N; i++)
        {
            vector<int> vis(N + 1, 0);
            maxd = 0;
            dfs(i, adj, vis, 0);

            ans = min(ans, maxd);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, x, y;
        cin >> N;
        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < N - 1; i++)
        {
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }

        Solution ob;
        cout << ob.partyHouse(N, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends
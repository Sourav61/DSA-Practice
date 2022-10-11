// https://leetcode.com/problems/number-of-provinces/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;

        for (auto x : adj[node])
        {
            if (!vis[x])
            {
                dfs(x, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ans++;
                dfs(i, adj, vis);
            }
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    cout << obj.findCircleNum(isConnected);

    return 0;
}
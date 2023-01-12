// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> res;
    vector<int> dfs(int curr, int par, vector<int> adj[], string &labels)
    {
        vector<int> cnt(26, 0);
        cnt[labels[curr] - 'a']++;

        for (auto &x : adj[curr])
        {
            if (x == par)
            {
                continue;
            }
            vector<int> sub = dfs(x, curr, adj, labels);
            for (int i = 0; i < 26; i++)
            {
                cnt[i] += sub[i];
            }
        }

        res[curr] = cnt[labels[curr] - 'a'];

        return cnt;
    }

    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        vector<int> adj[n];
        res.resize(n, 0);

        for (auto &x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        dfs(0, -1, adj, labels);

        return res;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};

    string labels = "abaedcd";

    cout << obj.countSubTrees(7, edges, labels);

    return 0;
}
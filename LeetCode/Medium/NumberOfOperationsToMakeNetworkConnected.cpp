// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class DisjointSet
    {
    public:
        vector<int> rank, parent;
        DisjointSet(int n)
        {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++)
            {
                parent[i] = i;
            }
        }

        int findParent(int node)
        {
            if (parent[node] == node)
            {
                return node;
            }

            return parent[node] = findParent(parent[node]);
        }

        void unionByRank(int u, int v)
        {
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if (ulp_u == ulp_v)
                return;

            if (rank[ulp_u] < rank[ulp_v])
            {
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] < rank[ulp_u])
            {
                parent[ulp_v] = ulp_u;
            }
            else
            {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    };

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DisjointSet ds(n);

        int extras = 0;

        for (auto &x : connections)
        {
            int u = x[0];
            int v = x[1];

            if (ds.findParent(u) == ds.findParent(v))
            {
                extras++;
            }
            else
            {
                ds.unionByRank(u, v);
            }
        }

        int compo = 0;

        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                compo++;
        }

        int ans = compo - 1;

        if (extras >= ans)
        {
            return ans;
        }

        return -1;
    }
};

int main()
{
    Solution obj;

    cout << obj.makeConnected(4, {{0, 1}, {0, 2}, {1, 2}});

    return 0;
}
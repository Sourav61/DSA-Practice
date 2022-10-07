// https://leetcode.com/problems/redundant-connection/

#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> par, rank;

public:
    DSU(int n) : par(n), rank(n)
    {
        iota(par.begin(), par.end(), 0);
    }

    int find(int x)
    {
        if (x == par[x])
            return x;

        return par[x] = find(par[x]);
    }

    bool Union(int x, int y)
    {
        int xp = find(x);
        int yp = find(y);

        if (xp == yp)
            return false;

        if (rank[xp] > rank[yp])
            par[yp] = par[xp];
        else if (rank[xp] < rank[yp])
            par[xp] = par[yp];
        else
            par[yp] = xp, rank[xp]++;

        return true;
    }
}

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        DSU ds(n + 1);

        for (auto &e : edges)
        {
            if (!ds.Union(E[0], E[1]))
                return E;
        }

        return {};
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};

    vector<int> res = obj.findRedundantConnection(edges);

    for (auto x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}
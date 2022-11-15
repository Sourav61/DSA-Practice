// https://leetcode.com/problems/accounts-merge/description/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

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

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();

        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end())
                {
                    mapMailNode[mail] = i;
                }
                else
                {
                    ds.unionByRank(mapMailNode[mail], i);
                }
            }
        }

        vector<string> mergedMails[n];

        for (auto &x : mapMailNode)
        {
            string mail = x.first;
            int node = ds.findPar(x.second);

            mergedMails[node].push_back(mail);
        }

        vector<vector<string>> res;

        for (int i = 0; i < n; i++)
        {
            if (mergedMails[i].size() == 0)
                continue;

            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (auto &x : mergedMails[i])
            {
                temp.push_back(x);
            }

            res.push_back(temp);
        }

        return res;
    }
};

int main()
{
    Solution obj;

    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"John", "johnsmith@mail.com", "john00@mail.com"}, {"Mary", "mary@mail.com"}, {"John", "johnnybravo@mail.com"}};

    vector<vector<string>> res = obj.accountsMerge(accounts);

    for (auto &v : res)
    {
        for (auto &x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
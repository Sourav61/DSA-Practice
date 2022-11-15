// https://practice.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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

    int Solve(int n, vector<vector<int>> &edge)
    {
        DisjointSet ds(n);

        int extras = 0;

        for (auto &x : edge)
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

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 2; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends
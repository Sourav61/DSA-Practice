// https://practice.geeksforgeeks.org/problems/number-of-pairs-1645358985/1?page=1&category[]=Disjoint%20Set&sortBy=submissions

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet
{
    vector<int> parent, rank;

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

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
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
    long long int numberOfPairs(vector<vector<int>> &pairs, int p, int n)
    {
        DisjointSet ds(n);

        for (int i = 0; i < p; i++)
        {
            ds.unionByRank(pairs[i][0], pairs[i][1]);
        }

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[ds.findPar(i)]++;
        }

        long long ans = 0;
        for (auto &x : mp)
        {
            ans += (x.second * (n - x.second));
        }

        return ans / 2;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        vector<vector<int>> pairs(p, vector<int>(2));
        for (auto &i : pairs)
            for (auto &j : i)
                cin >> j;
        Solution a;
        cout << a.numberOfPairs(pairs, p, n) << endl;
    }
}
// } Driver Code Ends
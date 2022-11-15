// https://practice.geeksforgeeks.org/problems/merging-details/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
    vector<vector<string>> mergeDetails(vector<vector<string>> &details)
    {
        int n = details.size();

        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < details[i].size(); j++)
            {
                string mail = details[i][j];
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
            temp.push_back(details[i][0]);

            for (auto &x : mergedMails[i])
            {
                temp.push_back(x);
            }

            res.push_back(temp);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++)
        {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++)
            {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(), res.end(), [](const vector<string> &a, const vector<string> &b)
             { return a[0] <= b[0]; });
        cout << "[";
        for (int i = 0; i < res.size(); ++i)
        {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++)
            {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    }
}

// } Driver Code Ends
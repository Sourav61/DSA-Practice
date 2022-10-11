// https://practice.geeksforgeeks.org/problems/number-of-provinces/1?page=1&status[]=unsolved&category[]=Graph&sortBy=submissions

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void dfs(int node, vector<int> adjLs[], vector<int> &vis)
    {
        vis[node] = 1;

        for (auto x : adjLs[node])
        {
            if (!vis[x])
            {
                dfs(x, adjLs, vis);
            }
        }
    }

    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<int> adjLs[V];

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);

        int ans = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                ans++;
                dfs(i, adjLs, vis);
            }
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
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
}
// } Driver Code Ends
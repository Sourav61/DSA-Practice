// https://practice.geeksforgeeks.org/problems/hamiltonian-path2522/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(int n, vector<int> adj[], vector<int> &vist, int src)
    {
        if (n == 0)
        {
            return true;
        }
        vist[src] = 1;
        for (auto &x : adj[src])
        {
            if (vist[x] == 0)
            {
                if (dfs(n - 1, adj, vist, x))
                {
                    return true;
                }
            }
        }
        vist[src] = 0;
        return false;
    }

    bool check(int n, int m, vector<vector<int>> e)
    {
        // code here
        vector<int> adj[n + 1];

        for (auto &x : e)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int> vist(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (dfs(n - 1, adj, vist, i))
            {
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M, X, Y;
        cin >> N >> M;
        vector<vector<int>> Edges;
        for (int i = 0; i < M; i++)
        {
            cin >> X >> Y;
            Edges.push_back({X, Y});
        }
        Solution obj;
        if (obj.check(N, M, Edges))
        {
            cout << "1" << endl;
        }
        else
            cout << "0" << endl;
    }
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/51afa710a708c0681748445b509696dd588d5c40/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long res = -1;
    void dfs(int node, int N, vector<int> &Edge, vector<bool> &vis, vector<bool> &pathVis)
    {
        vis[node] = true;
        pathVis[node] = true;

        if (Edge[node] != -1)
        {
            int adj = Edge[node];
            if (!vis[adj])
            {
                dfs(adj, N, Edge, vis, pathVis);
            }
            if (vis[adj] && pathVis[adj])
            {
                int curr = adj;
                long long sum = 0;
                do
                {
                    sum += curr;
                    curr = Edge[curr];
                } while (curr != adj);
                res = max(res, sum);
            }
        }

        pathVis[node] = false;
    }

    long long largestSumCycle(int N, vector<int> Edge)
    {
        vector<bool> vis(N, 0), pathVis(N, 0);

        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                dfs(i, N, Edge, vis, pathVis);
            }
        }

        return res;
    }
};

//{ Driver Code Starts.
signed main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N;
        cin >> N;
        vector<int> Edge(N);
        for (int i = 0; i < N; i++)
        {
            cin >> Edge[i];
        }
        Solution obj;
        long long ans = obj.largestSumCycle(N, Edge);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
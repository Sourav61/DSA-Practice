// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        vector<int> dist(n, 1e8);

        dist[0] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (auto x : edges)
            {
                if (dist[x[0]] + x[2] < dist[x[1]])
                {
                    dist[x[1]] = dist[x[0]] + x[2];
                }
            }
        }

        bool fl = 0;

        for (auto x : edges)
        {
            if (dist[x[0]] + x[2] < dist[x[1]])
            {
                fl = 1;
                return {1};
                break;
            }
        }

        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
        }
        Solution obj;
        int ans = obj.isNegativeWeightCycle(n, edges);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
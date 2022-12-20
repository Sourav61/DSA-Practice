// https://practice.geeksforgeeks.org/problems/alex-travelling/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int minimumCost(vector<vector<int>> &flights, int n, int k)
    {
        vector<pair<int, int>> adj[n + 1];

        for (auto &x : flights)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }

        vector<int> dist(n + 1, 1e9);

        queue<int> q;

        dist[k] = 0;

        q.push(k);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto &x : adj[curr])
            {
                if (dist[x.first] > dist[curr] + x.second)
                {
                    q.push(x.first);
                    dist[x.first] = dist[curr] + x.second;
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, dist[i]);
        }

        return ans == 1e9 ? -1 : ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size, vector<int>(3));
        for (int i = 0; i < size; i++)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i] = temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends
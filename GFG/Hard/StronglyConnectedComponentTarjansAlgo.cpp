// https://practice.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int timer = 0;
    vector<vector<int>> res;

    void dfs(int u, vector<int> &disc, vector<int> &low, stack<int> &st, vector<bool> &inStack, vector<int> adj[])
    {
        disc[u] = low[u] = timer++;
        st.push(u);
        inStack[u] = true;

        for (int v : adj[u])
        {
            if (disc[v] == -1)
            {
                dfs(v, disc, low, st, inStack, adj);
                low[u] = min(low[u], low[v]);
            }
            else if (inStack[v])
            {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (low[u] == disc[u])
        {
            vector<int> ans;
            while (st.top() != u)
            {
                ans.push_back(st.top());
                inStack[st.top()] = false;
                st.pop();
            }
            ans.push_back(st.top());
            inStack[st.top()] = false;
            st.pop();
            sort(ans.begin(), ans.end());
            res.push_back(ans);
        }
    }

    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> inStack(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (disc[i] == -1)
            {
                dfs(i, disc, low, st, inStack, adj);
            }
        }
        sort(res.begin(), res.end());
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
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for (int i = 0; i < ptr.size(); i++)
        {
            for (int j = 0; j < ptr[i].size(); j++)
            {
                if (j == ptr[i].size() - 1)
                    cout << ptr[i][j];
                else
                    cout << ptr[i][j] << " ";
            }
            cout << ',';
        }
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
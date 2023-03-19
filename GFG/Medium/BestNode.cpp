// https://practice.geeksforgeeks.org/problems/a3493283697b7b69573a840f371a55ccd9332bb0/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

typedef long long ll;
class Solution
{
public:
    pair<ll, ll> dfs(int i, vector<int> adj[], vector<int> &a, ll &ans)
    {
        ll minVal = 1e10, maxVal = -1e10;

        if (adj[i].size() == 0)
        {
            ll ans1 = a[i - 1];
            ans = max(ans, ans1);
            return {ans1, ans1};
        }

        for (auto &x : adj[i])
        {
            auto childVal = dfs(x, adj, a, ans);
            minVal = min(minVal, a[i - 1] - childVal.second);
            maxVal = max(maxVal, a[i - 1] - childVal.first);
        }

        ans = max(ans, maxVal);
        return {minVal, maxVal};
    }

    long long bestNode(int N, vector<int> &A, vector<int> &P)
    {
        vector<int> adj[N + 1];

        for (int i = 1; i < N; i++)
        {
            adj[P[i]].push_back(i + 1);
        }

        ll ans = -1e18;
        dfs(1, adj, A, ans);

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        vector<int> A(N);
        Array::input(A, N);

        vector<int> P(N);
        Array::input(P, N);

        Solution obj;
        long long res = obj.bestNode(N, A, P);

        cout << res << endl;
    }
}

// } Driver Code Ends
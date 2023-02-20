// https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
// Position this line where user code will be pasted.

class Solution
{
public:
    int f(int idx, int *cost, int N, int W, vector<vector<int>> &dp)
    {
        if (W == 0)
        {
            return 0;
        }

        if (idx > N)
        {
            return 1e9;
        }

        if (W < idx)
        {
            return 1e9;
        }

        if (dp[idx][W] != -1)
        {
            return dp[idx][W];
        }

        int notTake = f(idx + 1, cost, N, W, dp);
        int take = 1e9;
        if (cost[idx - 1] != -1)
        {
            take = cost[idx - 1] + f(idx, cost, N, W - idx, dp);
        }

        return dp[idx][W] = min(take, notTake);
    }

    int minimumCost(int cost[], int N, int W)
    {
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
        if (W == 0)
        {
            return 0;
        }
        int res = f(1, cost, N, W, dp);

        return res == 1e9 ? -1 : res;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minimumCost(a, n, w) << "\n";
    }
    return 0;
}
// } Driver Code Ends
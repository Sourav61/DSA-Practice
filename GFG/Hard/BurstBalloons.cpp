// https://practice.geeksforgeeks.org/problems/burst-balloons/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<vector<int>> dp;

    int solve(vector<int> &a, int st, int end)
    {
        if (end - st == 1)
            return 0;

        if (dp[st][end] != -1)
        {
            return dp[st][end];
        }

        int ans = 0;

        for (int m = st + 1; m < end; m++)
        {
            int curr = a[st] * a[m] * a[end] + solve(a, st, m) + solve(a, m, end);
            ans = max(ans, curr);
        }

        return dp[st][end] = ans;
    }

    int maxCoins(int N, vector<int> &arr)
    {
        vector<int> a(N + 2);
        int n = a.size();
        a[0] = a[n - 1] = 1;

        for (int i = 1; i <= n - 2; i++)
        {
            a[i] = arr[i - 1];
        }

        dp.resize(n, vector<int>(n, -1));

        return solve(a, 0, n - 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/e2d156755ca4e0a9b9abf5680191d4b06e52b1a8/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> dp;
    int goodStones(int n, vector<int> &arr)
    {
        dp.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (dp[i] == 0)
            {
                dp[i] = solve(i, n, arr);
            }
        }

        int ans = 0;

        for (auto &x : dp)
        {
            if (x == 2)
            {
                ans++;
            }
        }

        return ans;
    }

    int solve(int i, int n, vector<int> &arr)
    {
        if (i < 0 || i >= n)
        {
            return 2;
        }

        if (dp[i] == 1 || dp[i] == 2)
        {
            return dp[i];
        }

        dp[i] = 1;

        return dp[i] = solve(i + arr[i], n, arr);
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.goodStones(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
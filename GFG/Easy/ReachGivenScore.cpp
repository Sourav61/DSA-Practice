// https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1?page=1&status[]=bookmarked&sortBy=submissions

//{ Driver Code Starts
// Driver Code
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function
long long int count(long long int n)
{
    // Your code here
    long long int dp[n + 1], i;

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 3; i <= n; i++)
        dp[i] += dp[i - 3];

    for (int i = 5; i <= n; i++)
        dp[i] += dp[i - 5];

    for (int i = 10; i <= n; i++)
        dp[i] += dp[i - 10];

    return dp[n];
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << count(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends

class Solution
{
public:
    long long pairWithMaxSum(long long arr[], long long N)
    {
        long long maxi = INT_MIN;

        for (long long i = 1; i < N; i++)
            maxi = max(maxi, arr[i - 1] + arr[i]);

        return maxi;
    }
};

//{ Driver Code Starts.
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.pairWithMaxSum(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
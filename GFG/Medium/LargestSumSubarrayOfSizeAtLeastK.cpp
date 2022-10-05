// https://practice.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1

//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends

long long int maxSumWithK(long long int a[], long long int n, long long int k)
{
    long long int ans = INT_MIN, sum = 0;
    vector<long long int> temp;
    for (int i = 0; i < n; i++)
    {
        if (sum > 0)
            sum += a[i];
        else
            sum = a[i];
        temp.push_back(sum);
    }
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (i + 1 >= k)
        {
            ans = max({ans, sum + (i - k >= 0 ? temp[i - k] : 0), sum});
            sum -= a[i - k + 1];
        }
    }
    return ans;
}
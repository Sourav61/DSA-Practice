// https://practice.geeksforgeeks.org/problems/container-with-most-water0535/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
// User function template for C++

long long maxArea(long long A[], int len)
{
    long long ans = 0;
    int f = 0, h = len - 1;

    while (f < h)
    {
        ans = max(ans, (h - f) * min(A[f], A[h]));

        if (A[f] > A[h])
        {
            h = h - 1;
        }
        else
        {
            f = f + 1;
        }
    }

    return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << maxArea(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
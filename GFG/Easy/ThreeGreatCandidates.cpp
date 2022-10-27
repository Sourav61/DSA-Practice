// https://practice.geeksforgeeks.org/problems/three-great-candidates0515/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    long long maxProduct(int arr[], int n)
    {
        sort(arr, arr + n);

        long long neg = (long long)arr[0] * (long long)arr[1] * (long long)arr[n - 1];
        long long pos = (long long)arr[n - 3] * (long long)arr[n - 1] * (long long)arr[n - 2];

        if (neg > pos)
        {
            return neg;
        }

        return pos;
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
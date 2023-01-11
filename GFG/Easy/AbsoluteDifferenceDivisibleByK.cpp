// https://practice.geeksforgeeks.org/problems/e0059183c88ab680b2f73f7d809fb8056fe9dc43/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long countPairs(int n, int arr[], int k)
    {
        unordered_map<int, int> mp;

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int rem = arr[i] % k;

            if (rem != 0)
            {
                ans += mp[arr[i] % k];
            }
            else
            {
                ans += mp[0];
            }

            mp[rem]++;
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cin >> k;

        Solution ob;
        cout << ob.countPairs(n, arr, k) << endl;
    }
    return 0;
}
// } Driver Code Ends
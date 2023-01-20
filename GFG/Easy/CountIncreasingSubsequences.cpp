// https://practice.geeksforgeeks.org/problems/count-increasing-subsequences3134/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    unsigned long long int countSub(int arr[], int n)
    {
        vector<unsigned long long int> dp(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j])
                {
                    dp[i] = dp[i] + dp[j];
                }
            }
        }
        unsigned long long int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = res + dp[i];
        }
        return res;
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
        int a[n + 1];
        for (unsigned long long int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.countSub(a, n) << endl;
    }
}

// } Driver Code Ends
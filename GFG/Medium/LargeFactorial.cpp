// https://practice.geeksforgeeks.org/problems/large-factorial4721/1/?page=3&difficulty[]=1&status[]=unsolved&category[]=Arrays&category[]=Recursion&sortBy=submissions#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    vector<long long> factorial(vector<long long> a, int n)
    {
        long long maxi = INT_MIN;
        // if number is negative
        for (int i = 0; i < n; i++)
        {
            if (maxi < a[i])
            {
                maxi = a[i];
            }
        }
        vector<long long> dp(maxi + 1, -1);
        vector<long long> ans;
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < maxi + 1; i++)
        {
            dp[i] = i * dp[i - 1] % 1000000007;
        }
        for (int i = 0; i < n; i++)
        {
            ans.push_back(dp[a[i]]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
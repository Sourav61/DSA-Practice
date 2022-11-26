// https://practice.geeksforgeeks.org/problems/shreyansh-and-his-bits1420/1

//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long dp[40][40];
    long long count(long long x)
    {
        for (int i = 0; i < 40; i++)
            for (int j = 0; j < 40; j++)
                dp[i][j] = -1;

        long long ans = 0;
        int bor = 0;
        int ones = 0;

        while (x > 0)
        {
            if (x & 1)
            {
                ones++;
                ans += nCr(bor, ones);
            }

            x /= 2;
            bor++;
        }

        return ans;
    }

    long long nCr(int n, long long int r)
    {
        if (r > n)
        {
            return 0;
        }

        if (r == 0 || r == n)
        {
            return 1;
        }

        if (dp[n][r] != -1)
            return dp[n][r];

        return dp[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t-- > 0)
    {
        long long x;
        cin >> x;
        Solution ob;
        cout << ob.count(x) << '\n';
    }
    return 0;
}
// } Driver Code Ends
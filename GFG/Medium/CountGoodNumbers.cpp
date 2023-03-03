// https://practice.geeksforgeeks.org/problems/count-good-numbers/1?page=1&sortBy=newest&query=page1sortBynewest

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int mod = (int)(1e9 + 7);
    long long pow(long long x, long n)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (n % 2 == 0)
        {
            long long y = pow(x, n / 2);
            return (y * y) % mod;
        }

        return (x * pow(x, n - 1)) % mod;
    }

    int countGoodNumbers(long long N)
    {
        long long even = 0, odd = 0;

        if ((N % 2) != 0)
        {
            even = (N / 2) + 1;
            odd = (N / 2);
        }
        else
        {
            even = (N / 2);
            odd = (N / 2);
        }

        return (long long)((long long)(pow(5, even)) % mod * (long long)(pow(4, odd)) % mod) % mod;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin >> N;
        Solution ob;

        cout << ob.countGoodNumbers(N) << endl;
    }
}
// } Driver Code Ends
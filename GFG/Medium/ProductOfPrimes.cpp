// https://practice.geeksforgeeks.org/problems/product-of-primes5328/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isprime(long long n)
    {
        for (long long i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    long long primeProduct(long long L, long long R)
    {
        long long mult = 1;

        for (long long i = L; i <= R; i++)
            if (isprime(i))
                mult = (mult * i) % 1000000007;

        return mult;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long L, R;
        cin >> L >> R;

        Solution ob;
        cout << ob.primeProduct(L, R) << "\n";
    }
    return 0;
}
// } Driver Code Ends
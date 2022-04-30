// https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1/#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long fib[100001] = {0, 1, 2, 0};

    long long numberOfWays(long long N)
    {

        if (fib[N] != 0)
        {
            return fib[N];
        }

        fib[N] = (numberOfWays(N - 1) + numberOfWays(N - 2)) % 1000000007;
        return fib[N];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;

        cin >> N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
} // } Driver Code Endss
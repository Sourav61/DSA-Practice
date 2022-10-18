// https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long int nthFibonacci(long long int n)
    {
        long long int prev2 = 0;
        long long int prev = 1;

        for (int i = 2; i <= n; i++)
        {
            long long int curi = (prev + prev2) % 1000000007;
            prev2 = prev;
            prev = curi;
        }

        return prev;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
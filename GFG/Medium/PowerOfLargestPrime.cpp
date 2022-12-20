// https://practice.geeksforgeeks.org/problems/power-of-largest-prime3452/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int largePrime(long long n)
    {
        if (n == 1)
        {
            return 0;
        }

        int count = 0;

        while (n % 2 == 0)
        {
            count++;
            n = n / 2;
        }

        for (int i = 3; i <= sqrt(n); i += 2)
        {
            if (n % i == 0)
                count = 0;
            while (n % i == 0)
            {
                count++;
                n = n / i;
            }
        }

        if (n > 2)
        {
            count = 1;
        }

        return count != 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        Solution ob;
        if (ob.largePrime(n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
// } Driver Code Ends
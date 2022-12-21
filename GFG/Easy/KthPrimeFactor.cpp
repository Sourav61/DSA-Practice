// https://practice.geeksforgeeks.org/problems/kth-prime-factor-of-a-number0132/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int kthPrime(int n, int k)
    {
        if (n == 0 || n < k)
        {
            return -1;
        }

        if (n % 2 == 0)
        {
            while (n % 2 == 0 && --k)
            {
                n /= 2;
            }
        }

        if (k == 0)
        {
            return 2;
        }

        for (int i = 3; i <= sqrt(n); i += 2)
        {
            while (n % i == 0 && --k)
            {
                n /= i;
            }
            if (k == 0)
            {
                return i;
            }
        }

        if (n > 2 && k == 1)
        {
            return n;
        }

        return -1;
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
        cin >> n >> k;

        Solution ob;
        cout << ob.kthPrime(n, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends
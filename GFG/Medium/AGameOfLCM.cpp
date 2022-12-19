// https://practice.geeksforgeeks.org/problems/a-game-of-lcm2531/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long gcd(long long a, long long b)
    {
        if (a == 0)
            return b;

        return gcd(b % a, a);
    }

    long long solve(int N)
    {
        long long x = (N * (N - 1)) / gcd(N, N - 1);
        long long y = ((N - 2) * (N - 3)) / gcd(N - 2, N - 3);

        long long z = (x * y) / gcd(x, y);
        long long num = N * (N - 1);
        int count = 0;
        for (int i = N - 2; i >= 1; i--)
        {
            if (gcd(num, i) == 1)
            {
                num *= i;
                count++;
            }
            if (count == 2)
            {
                break;
            }
        }

        return max(num, z);
    }

    long long maxGcd(int N)
    {
        return max(solve(N), solve(N - 1));
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends
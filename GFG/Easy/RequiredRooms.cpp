// https://practice.geeksforgeeks.org/problems/required-rooms3939/1/#

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int rooms(int N, int M)
    {
        int sum = N + M;
        while (M != 0)
        {
            int rem = N % M;
            N = M;
            M = rem;
        }

        return (sum / N);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;

        Solution ob;
        cout << ob.rooms(N, M) << "\n";
    }
    return 0;
} // } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Bit%20Magic&sortBy=submissions#

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        int num = m ^ n, count = 1;
        while (num > 0)
        {
            if (num & 1)
            {
                return count;
            }
            count++;
            num = num >> 1;
        }

        return -1;
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t; // input number of testcases
    while (t--)
    {
        int m, n;
        cin >> m >> n; // input m and n
        Solution ob;
        cout << ob.posOfRightMostDiffBit(m, n) << endl;
    }
    return 0;
} // } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Bit%20Magic&sortBy=submissions#

// // { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        unsigned int count = 1;
        while (n > 0)
        {
            if (n & 1)
            {
                return count;
            }
            count++;
            n = n >> 1;
        }

        return 0;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n;
        cin >> n; // input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
    return 0;
}
// } Driver Code Ends
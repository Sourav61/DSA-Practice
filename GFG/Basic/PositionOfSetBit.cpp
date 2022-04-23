// https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Bit%20Magic&sortBy=submissions#

// // { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPosition(int N)
    {
        if (((N & (N - 1)) == 0) && N != 0)
        {
            int count = 1;
            while (N > 0)
            {
                if (N & 1)
                {
                    return count;
                }
                count++;
                N = N >> 1;
            }
            return count;
        }

        return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
} // } Driver Code Ends
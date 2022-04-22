// https://practice.geeksforgeeks.org/problems/set-bits0143/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Bit%20Magic&sortBy=submissions#

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int setBits(int N)
    {
        int count = 0;
        while (N)
        {
            N = N & N - 1;
            count++;
        }
        return count;
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
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
// } Driver Code Ends
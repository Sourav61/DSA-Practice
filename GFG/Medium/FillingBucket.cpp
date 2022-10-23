// https://practice.geeksforgeeks.org/problems/filling-bucket0529/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int fillingBucket(int N)
    {
        int prev2 = 1, prev = 2;
        if (N <= 2)
            return N;

        int curi;
        int mod = 1e8;

        for (int i = 2; i < N; i++)
        {
            curi = (prev % mod + prev2 % mod) % mod;
            prev2 = prev;
            prev = curi;
        }

        return curi;
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
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
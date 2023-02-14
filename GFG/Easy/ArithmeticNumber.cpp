// https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int inSequence(int A, int B, int C)
    {
        if (C == 0)
            return A == B;

        int d = (B - A) / C;
        int r = (B - A) % C;

        return d >= 0 && r == 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B, C;
        cin >> A >> B >> C;

        Solution ob;
        cout << ob.inSequence(A, B, C) << endl;
    }
    return 0;
}
// } Driver Code Ends
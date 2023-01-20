// https://practice.geeksforgeeks.org/problems/230d87552a332a2970b2092451334a007f2b0eec/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int carpetBox(int A, int B, int C, int D)
    {
        int len = A, wid = B;
        int steps = 0, stepsRotated = 0;

        while (len > C || wid > D)
        {
            if (len > C)
            {
                steps++;
                len /= 2;
            }
            if (wid > D)
            {
                steps++;
                wid /= 2;
            }
        }

        len = B, wid = A;

        while (len > C || wid > D)
        {
            if (len > C)
            {
                stepsRotated++;
                len /= 2;
            }
            if (wid > D)
            {
                stepsRotated++;
                wid /= 2;
            }
        }

        return min(steps, stepsRotated);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        Solution ob;

        int ans = ob.carpetBox(A, B, C, D);

        cout << ans << endl;
    }
}
// } Driver Code Ends
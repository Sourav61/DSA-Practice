// https://practice.geeksforgeeks.org/problems/missing-point-of-a-parallelogram0146/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<double> findPoint(int A[], int B[], int C[])
    {
        int x, y;
        if ((A[0] + B[0] - C[0]) < (A[0] + C[0] - B[0]))
        {
            x = A[0] + B[0] - C[0];
            y = A[1] + B[1] - C[1];
        }
        else if ((A[0] + B[0] - C[0]) == (A[0] + C[0] - B[0]))
        {
            x = A[0] + B[0] - C[0];
            y = min(A[1] + B[1] - C[1], A[1] + C[1] - B[1]);
        }
        else
        {
            x = A[0] + C[0] - B[0];
            y = A[1] + C[1] - B[1];
        }
        if (x > C[0] + B[0] - A[0])
        {
            x = C[0] + B[0] - A[0];
            y = C[1] + B[1] - A[1];
        }
        else if (x == C[0] + B[0] - A[0])
            y = min(y, C[1] + B[1] - A[1]);

        return {(double)x, (double)y};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A[2];
        int B[2];
        int C[2];
        cin >> A[0] >> A[1] >> B[0] >> B[1] >> C[0] >> C[1];
        Solution ob;
        vector<double> ans = ob.findPoint(A, B, C);
        printf("%0.6f %0.6f\n", ans[0], ans[1]);
    }
}

// } Driver Code Ends
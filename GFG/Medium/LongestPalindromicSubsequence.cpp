// https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int longestPalinSubseq(string A)
    {
        string B = A;
        reverse(B.begin(), B.end());

        int n = A.length();

        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        for (int j = 0; j <= n; j++)
        {
            prev[j] = 0;
        }

        int maxLen = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (A[i - 1] == B[j - 1])
                {
                    cur[j] = 1 + prev[j - 1];
                }
                else
                {
                    cur[j] = max(prev[j], cur[j - 1]);
                }

                maxLen = max(maxLen, cur[j]);
            }

            prev = cur;
        }

        return maxLen;
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
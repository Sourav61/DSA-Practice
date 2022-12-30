// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> curr(n + 1, 0), ahead(n + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev = ind - 1; prev >= -1; prev--)
            {
                int len = 0 + ahead[prev + 1];

                if (prev == -1 || a[ind] > a[prev])
                {
                    len = max(len, 1 + ahead[ind + 1]);
                }

                curr[prev + 1] = len;
            }
            ahead = curr;
        }

        return curr[0];
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
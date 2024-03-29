// https://practice.geeksforgeeks.org/problems/shortest-job-first/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution
{
public:
    int solve(vector<int> &bt)
    {
        sort(bt.begin(), bt.end());

        int n = bt.size();
        int ct = 0, totwt = 0;
        for (int i = 0; i < n; i++)
        {
            ct += bt[i];
            totwt = totwt + ct - bt[i];
        }
        return totwt / n;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> bt[i];
        }
        Solution obj;
        int ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
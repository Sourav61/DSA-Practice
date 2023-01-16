// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-85/instructions/#

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long minimumCost(int n, vector<int> &p)
    {
        vector<int> rank(n, 0);
        long long cost = 0;
        for (int i = 1; i < n; i++)
        {
            rank[i]++;
            rank[p[i] - 1]++;
            cost += (rank[i] * rank[p[i] - 1]);
        }

        return cost;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];
        Solution obj;
        long long ans = obj.minimumCost(n, p);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/7995e41d167d81f14f1d4194b29ef839f52d18ba/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minimumTime(int N, int cur, vector<int> &pos, vector<int> &time)
    {
        int res = INT_MAX;
        for (int i = 0; i < N; i++)
        {
            res = min(res, abs(pos[i] - cur) * time[i]);
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, cur;
        cin >> N >> cur;
        vector<int> pos(N), time(N);
        for (int i = 0; i < N; i++)
        {
            cin >> pos[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> time[i];
        }
        Solution ob;
        cout << ob.minimumTime(N, cur, pos, time) << endl;
    }
}
// } Driver Code Ends
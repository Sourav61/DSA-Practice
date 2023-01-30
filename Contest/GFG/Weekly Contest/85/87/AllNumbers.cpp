// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-87/problems/#

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<long long> allNumbers(long long A, long long B)
    {
        vector<long long> res;
        long long temp = A;

        while (A <= B)
        {
            if (B % A == 0)
            {
                res.push_back(A);
            }
            A += temp;
        }

        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        Solution obj;
        vector<long long> ans = obj.allNumbers(a, b);
        for (long long i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
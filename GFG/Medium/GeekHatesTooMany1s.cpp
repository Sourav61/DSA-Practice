// https://practice.geeksforgeeks.org/problems/07e45fe40846bc670ad2507d2c649304699768b9/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

public:
    int noConseBits(int n)
    {
        vector<int> res(32, 0);

        for (int i = 31; i >= 0; i--)
        {
            if ((n & (1 << (31 - i))) != 0)
            {
                res[i] = 1;
            }
        }

        int ans = 0;

        for (int i = 0; i <= 29; i++)
        {
            if (res[i] == 1)
            {
                ans += (1 << (31 - i));
                if (res[i + 1] == 1)
                {
                    res[i + 2] = 0;
                }
            }
        }

        if (res[30] == 1)
        {
            ans += 2;
        }
        if (res[31] == 1)
        {
            ans += 1;
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--)
    {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends
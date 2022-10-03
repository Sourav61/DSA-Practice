// https://practice.geeksforgeeks.org/problems/modified-numbers-and-queries0904/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int sumOfAll(int l, int r)
    {
        int ans = 0;

        vector<bool> res(r + 1, true);

        for (int i = 2; i <= r; i++)
        {
            if (res[i])
            {
                for (int j = i * i; j <= r; j += i)
                {
                    res[j] = false;
                }
            }
        }

        while (l <= r)
        {
            if (l == 1)
            {
                l++;
                ans++;
                continue;
            }

            int curr = 0;
            for (int i = 2; i <= l; i++)
            {
                if (res[i] && l % i == 0)
                {
                    curr += i;
                }
            }

            ans += curr;
            l++;
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        Solution ob;
        cout << ob.sumOfAll(l, r) << endl;
    }
    return 0;
}

// } Driver Code Ends
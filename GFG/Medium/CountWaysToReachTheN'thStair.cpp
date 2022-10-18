// https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        int prev2 = 1;
        int prev = 1;

        for (int i = 2; i <= n; i++)
        {
            int curi = (prev + prev2) % 1000000007;
            prev2 = prev;
            prev = curi;
        }

        return prev;
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends
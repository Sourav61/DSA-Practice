// https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int mod = (int)(1e9 + 7);
    int distinctSubsequences(string s)
    {
        int n = s.length();
        vector<long long int> dp(n + 1);
        dp[0] = 1;

        unordered_map<char, int> mp;

        for (int i = 1; i <= n; i++)
        {
            dp[i] = 2 * dp[i - 1];
            char ch = s[i - 1];

            if (mp.find(ch) != mp.end())
            {
                int j = mp[ch];
                dp[i] = dp[i] - dp[j - 1];
            }

            mp[ch] = i;
        }

        return dp[n] % mod;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.distinctSubsequences(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends
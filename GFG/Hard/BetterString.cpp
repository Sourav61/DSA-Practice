// https://practice.geeksforgeeks.org/problems/better-string/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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

    string betterString(string str1, string str2)
    {
        int a = distinctSubsequences(str1);
        int b = distinctSubsequences(str2);

        if (a >= b)
        {
            return str1;
        }
        return str2;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends
// https://leetcode.com/problems/distinct-subsequences-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = (int)(1e9 + 7);

    int distinctSubseqII(string s)
    {
        int n = s.length();

        unordered_map<char, int> mp;

        vector<long long int> dp(n + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            dp[i] = 2 * dp[i - 1];
            char ch = s[i - 1];

            if (mp.find(ch) != mp.end())
            {
                int j = mp[ch];
                dp[i] = (dp[i] - dp[j - 1] + mod) % mod;
            }

            mp[ch] = i;
        }

        return (dp[n] - 1 + mod) % mod;
    }
};

int main()
{
    Solution obj;

    cout << obj.distinctSubseqII("abc") << endl;

    return 0;
}
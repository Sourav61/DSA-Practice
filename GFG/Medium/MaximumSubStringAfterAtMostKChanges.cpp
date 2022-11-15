// https://practice.geeksforgeeks.org/problems/maximum-sub-string-after-at-most-k-changes3220/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.length();

        if (k < 0)
        {
            return 0;
        }

        unordered_map<char, int> mp;

        int maxLen;
        int start, end;
        int maxFreq;

        maxLen = start = end = maxFreq = 0;

        while (end < n)
        {
            mp[s[end]]++;

            maxFreq = max(maxFreq, mp[s[end]]);
            int winSize = end - start + 1;
            if (winSize - maxFreq > k)
            {
                mp[s[start]]--;
                start++;
            }
            else
            {
                maxLen = max(maxLen, winSize);
            }

            end++;
        }

        return maxLen;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution obj;
        int ans = obj.characterReplacement(s, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
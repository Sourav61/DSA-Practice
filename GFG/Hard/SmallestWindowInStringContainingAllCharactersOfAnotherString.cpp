// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow(string s, string t)
    {
        if (s.length() == 0 || s.length() < t.length())
        {
            return "-1";
        }

        unordered_map<char, int> mp;

        for (auto &x : t)
        {
            mp[x]++;
        }

        int cnt = 0, st = 0, minLen = INT_MAX, minLeft = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] > 0)
            {
                cnt++;
            }

            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]]--;
            }

            while (cnt == t.length())
            {
                if (minLen > i - st + 1)
                {
                    minLen = i - st + 1;
                    minLeft = st;
                }

                if (mp.find(s[st]) != mp.end())
                {
                    mp[s[st]]++;
                    if (mp[s[st]] > 0)
                        cnt--;
                }
                st++;
            }
        }

        if (minLen > s.length())
        {
            return "-1";
        }

        return s.substr(minLeft, minLen);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends
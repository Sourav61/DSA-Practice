// https://leetcode.com/problems/minimum-window-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.length() == 0 || s.length() < t.length())
        {
            return "";
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
            return "";
        }

        return s.substr(minLeft, minLen);
    }
};

int main()
{

    Solution obj;

    cout << obj.minWindow("ADOBECODEBANC", "ABC");

    return 0;
}
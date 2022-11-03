// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        int n = words.size();

        unordered_map<string, int> mp;

        for (auto &x : words)
        {
            mp[x]++;
        }

        int res = 0;

        bool centre = false;

        for (auto &x : mp)
        {
            if (x.first[0] == x.first[1])
            {
                if (x.second % 2 == 0)
                {
                    res += x.second;
                }
                else
                {
                    res += x.second - 1;
                    centre = true;
                }
            }
            else
            {
                string temp = x.first;
                reverse(temp.begin(), temp.end());
                if (mp.find(temp) != mp.end())
                {
                    int cnt = min(mp[temp], mp[x.first]);
                    res += cnt;
                }
            }
        }

        if (centre)
        {
            res++;
        }

        return 2 * res;
    }
};

int main()
{

    Solution obj;

    vector<string> words = {"ab", "ty", "yt", "lc", "cl", "ab"};

    cout << obj.longestPalindrome(words);

    return 0;
}
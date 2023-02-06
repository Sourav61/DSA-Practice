// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> mp;
        vector<int> res;
        if (p.size() > s.size())
        {
            return res;
        }
        int k = p.length();
        for (auto &x : p)
        {
            mp[x]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (i >= p.size())
            {
                mp[s[i - p.size()]]++;
            }
            mp[s[i]]--;

            int flag = 0;
            for (auto &x : mp)
            {
                if (x.second != 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                res.push_back(i - k + 1);
            }
        }

        return res;
    }
};

int main()
{

    Solution obj;

    cout << obj.findAnagrams("cbaebabacd", "abc");

    return 0;
}
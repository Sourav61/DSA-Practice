// https://leetcode.com/problems/permutation-in-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> mp;
        if (s1.size() > s2.size())
        {
            return 0;
        }

        for (auto &x : s1)
        {
            mp[x]++;
        }

        for (int i = 0; i < s2.size(); i++)
        {
            if (i >= s1.size())
                mp[s2[i - s1.size()]]++;
            mp[s2[i]]--;

            int flag = 0;
            for (auto &x : mp)
            {
                if (x.second != 0)
                {
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                return 1;
            }
        }

        return 0;
    }
};

int main()
{

    Solution obj;

    cout << obj.checkInclusion("ab", "eidbaooo");

    return 0;
}
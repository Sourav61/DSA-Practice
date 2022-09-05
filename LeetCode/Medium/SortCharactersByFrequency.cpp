// https://leetcode.com/problems/sort-characters-by-frequency/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        string ans;

        unordered_map<char, int> mp;

        priority_queue<pair<char, int>> maxH;

        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }

        for (auto x : mp)
        {
            maxH.push({x.second, x.first});
        }

        while (maxH.size() > 0)
        {
            for (int i = 0; i < maxH.top().second; i++)
            {
                ans += maxH.top().first;
            }

            maxH.pop();
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    cout << obj.frequencySort("tree");

    return 0;
}
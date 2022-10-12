// https://leetcode.com/problems/verifying-an-alien-dictionary/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<char, int> mp;
    bool checkOrder(string &a, string &b)
    {
        int minLen = min(a.length(), b.length());

        for (int ptr = 0; ptr < minLen; ptr++)
        {
            if (mp[a[ptr]] != mp[b[ptr]])
            {
                return mp[a[ptr]] < mp[b[ptr]];
            }
        }
        return size(a) <= size(b);
    }

    bool isAlienSorted(vector<string> &words, string order)
    {
        int len = order.length();

        for (int i = 0; i < len; i++)
        {
            mp[order[i]] = i;
        }

        int n = words.size();

        for (int i = 0; i < n - 1; i++)
        {
            string s1 = words[i];
            string s2 = words[i + 1];
            if (!checkOrder(s1, s2))
                return false;
        }

        return true;
    }
};

int main()
{

    Solution obj;

    vector<string> words = {"hello", "leetcode"};

    string order = "hlabcdefgijkmnopqrstuvwxyz";

    cout << obj.isAlienSorted(words, order);

    return 0;
}
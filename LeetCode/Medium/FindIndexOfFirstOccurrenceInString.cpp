// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string hay, string needle)
    {
        char ch = needle[0];
        int len = needle.length();
        int n = hay.length();

        for (int i = 0; i < n; i++)
        {
            if (hay[i] == ch)
            {
                string temp = hay.substr(i, len);
                if (temp == needle)
                {
                    return i;
                }
            }
        }

        return -1;
    }
};

int main()
{

    Solution obj;

    cout << obj.strStr("sadbutsad", "sad");

    return 0;
}
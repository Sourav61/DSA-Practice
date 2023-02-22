// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution
{
public:
    int minMaxDifference(int num)
    {
        string s = to_string(num);
        string str = s;

        int l = 0;

        while (s[l] == '9')
        {
            l++;
        }

        char fs = s[l];

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == fs)
            {
                s[i] = '9';
            }
        }

        char ch = str[0];
        for (int i = 0; i < s.size(); i++)
        {
            if (str[i] == ch)
            {
                str[i] = '0';
            }
        }

        return stoi(s) - stoi(str);
    }
};

int main()
{

    Solution obj;

    cout << obj.minMaxDifference(11891);

    return 0;
}
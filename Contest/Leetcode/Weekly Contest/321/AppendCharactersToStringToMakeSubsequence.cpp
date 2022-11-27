// https://leetcode.com/contest/weekly-contest-321/problems/append-characters-to-string-to-make-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int i, int j, string &s, string &t)
    {
        if (j == t.length())
        {
            return 0;
        }
        if (i > s.length())
        {
            // cout<<i<<" "<<j<<endl;
            return t.length() - j;
        }

        if (s[i] == t[j])
        {
            return f(i + 1, j + 1, s, t);
        }

        return f(i + 1, j, s, t);
    }

    int appendCharacters(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        return f(0, 0, s, t);
    }
};

int main()
{
    Solution obj;

    cout << obj.appendCharacters("coaching", "coding");

    return 0;
}
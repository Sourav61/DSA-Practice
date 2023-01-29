// https://leetcode.com/problems/restore-ip-addresses/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        int n = s.length();
        helper(s, n, 0, 0, "", res);

        return res;
    }

    void helper(string &s, int &n, int i, int parts, string ans, vector<string> &res)
    {
        if (parts == 4 || i == n)
        {
            if (i == n && parts == 4)
            {
                res.push_back(ans.substr(0, ans.length() - 1));
            }
            return;
        }

        helper(s, n, i + 1, parts + 1, ans + s[i] + ".", res);

        if (i + 2 <= n && isValid(s.substr(i, 2)))
        {
            helper(s, n, i + 2, parts + 1, ans + s.substr(i, 2) + ".", res);
        }
        if (i + 3 <= n && isValid(s.substr(i, 3)))
        {
            helper(s, n, i + 3, parts + 1, ans + s.substr(i, 3) + ".", res);
        }
    }

    bool isValid(string str)
    {
        if (str[0] == '0')
        {
            return false;
        }

        return (int)stoi(str) <= 255;
    }
};

int main()
{

    Solution obj;

    cout << obj.restoreIpAddresses("25525511135");

    return 0;
}
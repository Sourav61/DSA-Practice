// https://leetcode.com/problems/scramble-string/description/

#include <bitsstdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<string, bool> mp;

    bool sol(string s, string t)
    {
        int n = s.size();
        if (s == t || n == 0)
        {
            return true;
        }

        string key = s + "" + t;

        if (mp.find(key) != mp.end())
        {
            return mp[key];
        }

        bool flag = false;

        for (int i = 1; i < n; i++)
        {
            if (sol(s.substr(0, i), t.substr(n - i, i)) == true && sol(s.substr(i, n - i), t.substr(0, n - i)) == true)
            {
                flag |= true;
                break;
            }
            if (sol(s.substr(0, i), t.substr(0, i)) == true && sol(s.substr(i, n - i), t.substr(i, n - i)) == true)
            {
                flag |= true;
                break;
            }
        }

        return mp[key] = flag;
    }

    bool isScramble(string S1, string S2)
    {
        int n = S1.size();
        int m = S2.size();

        if (n != m)
        {
            return false;
        }

        if (S1 == "" && S2 == "")
        {
            return true;
        }

        return sol(S1, S2);
    }
};

int main()
{

    Solution obj;

    cout << obj.isScramble("great", "rgate");

    return 0;
}
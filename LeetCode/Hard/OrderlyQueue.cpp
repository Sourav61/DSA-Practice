// https://leetcode.com/problems/orderly-queue/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        if (k > 1)
        {
            sort(s.begin(), s.end());
            return s;
        }

        string ans = s;

        for (int i = 0; i < s.length(); i++)
        {
            s = s.substr(1) + s[0];
            int diff = ans.compare(s);
            if (diff > 0)
            {
                ans = s;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    cout << obj.orderlyQueue("cba", 1);

    return 0;
}
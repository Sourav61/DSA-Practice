// https://leetcode.com/problems/remove-k-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        int n = num.length();

        if (k == n)
        {
            return "0";
        }

        string res;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && k > 0 && st.top() > num[i])
            {
                st.pop();
                k--;
            }
            if (!st.empty() || num[i] != '0')
            {
                st.push(num[i]);
            }
        }

        while (!st.empty() && k--)
        {
            st.pop();
        }

        if (st.empty())
        {
            return "0";
        }

        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{

    Solution obj;

    cout << obj.removeKdigits("1432219", 3);

    return 0;
}
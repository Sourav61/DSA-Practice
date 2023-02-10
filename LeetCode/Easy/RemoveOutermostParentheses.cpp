// https://leetcode.com/problems/remove-outermost-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        stack<char> st;

        string res = "";
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];

            if (ch == '(')
            {
                if (st.size() > 0)
                {
                    res += ch;
                }
                st.push(ch);
            }
            else
            {
                st.pop();
                if (st.size() > 0)
                {
                    res += ch;
                }
            }
        }

        return res;
    }
};

int main()
{

    Solution obj;

    cout << obj.removeOuterParentheses("(()())(())(()(()))");

    return 0;
}
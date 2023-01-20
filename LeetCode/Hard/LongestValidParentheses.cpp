// https://leetcode.com/problems/longest-valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string S)
    {
        stack<int> s;
        s.push(-1);
        int res = 0;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == '(')
                s.push(i);
            else
            {
                s.pop();
                if (!s.empty())
                    res = max(res, i - s.top());
                else
                    s.push(i);
            }
        }
        return res;
    }
};

int main()
{
    Solution obj;

    cout << obj.longestValidParentheses("(()");

    return 0;
}
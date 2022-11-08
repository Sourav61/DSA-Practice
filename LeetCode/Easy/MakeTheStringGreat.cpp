// https://leetcode.com/problems/make-the-string-great/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        string res = "";
        int n = s.length();
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < n; i++)
        {
            if (!st.empty())
            {
                if (abs(s[i] - st.top()) == 32)
                {
                    st.pop();
                    continue;
                }
            }
            st.push(s[i]);
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

    cout << obj.makeGood("leEeetcode");

    return 0;
}
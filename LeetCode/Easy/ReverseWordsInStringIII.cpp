// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        int n = s.length();

        string temp = "";

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                st.push(temp);
                temp = "";
            }
            else
                temp += s[i];
        }

        if (temp != "")
        {
            st.push(temp);
        }

        string res = "";

        while (!st.empty())
        {
            res += st.top();
            if (st.size() > 1)
                res += " ";
            st.pop();
        }

        return res;
    }
};

int main()
{

    Solution obj;

    cout << obj.reverseWords("Let's take LeetCode contest") << endl;

    return 0;
}
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        string res;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            if (!st.empty() && st.top() == s[i])
            {
                st.pop();
                continue;
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

    cout << obj.removeDuplicates("azxxzy");

    return 0;
}
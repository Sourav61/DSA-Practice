// https://leetcode.com/problems/decode-string/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> cnt;
        stack<string> str;

        int res = "";

        int i = 0;

        while (i < n)
        {
            if (isdigit(s[i]))
            {
                int count = 0;
                while (isdigit(s[i]))
                {
                    count = count * 10 + s[i];
                    i++;
                }
                cnt.push(count);
            }
            else if (s[i] == '[')
            {
                str.push(res);
                res = "";
                i++;
            }
            else if (s[i] == ']')
            {
                int temp = str.top();
                str.pop();
                int count = cnt.top();
                cnt.pop();

                for (int i = 0; i < count; i++)
                {
                    temp += s;
                }
                res = temp;
                i++;
            }
            else
            {
                res += s[i];
                i++;
            }
        }

        return res;
    }
};

int main()
{

    Solution obj;

    cout << obj.decodeString(s) << endl;

    return 0;
}
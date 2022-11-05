// https://leetcode.com/problems/reverse-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        int i = 0, j = n - 1;

        while (i < j)
        {
            char ch = s[i];
            s[i] = s[j];
            s[j] = ch;

            i++;
            j--;
        }
    }
};

int main()
{

    Solution obj;

    cout << obj.reverseString("hello");

    return 0;
}
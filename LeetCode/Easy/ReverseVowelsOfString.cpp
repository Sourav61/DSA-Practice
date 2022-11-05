// https://leetcode.com/problems/reverse-vowels-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        int n = s.length();
        int i = 0, j = n - 1;

        string temp = s;

        while (i < n && j >= 0)
        {
            if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U')
            {
                i++;
                continue;
            }
            if (s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' && s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U')
            {
                j--;
                continue;
            }

            temp[i] = s[j];
            temp[j] = s[i];

            i++;
            j--;
        }

        return temp;
    }
};

int main()
{

    Solution obj;

    cout << obj.reverseVowels("hello");

    return 0;
}
// https://leetcode.com/problems/backspace-string-compare/

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int j = 0, k = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '#')
            {
                j--;
                j = max(0, j);
            }
            else
            {
                s[j] = s[i];
                j++;
            }
        }

        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == '#')
            {
                k--;
                k = max(0, k);
            }
            else
            {
                t[k] = t[i];
                k++;
            }
        }
        if (j != k)
            return false;
        else
        {
            for (int i = 0; i < k; i++)
            {
                if (s[i] != t[i])
                    return false;
            }
            return true;
        }
    }
};

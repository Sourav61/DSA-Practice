// https://leetcode.com/problems/detect-capital/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int n = word.size();

        if (word[0] >= 97 && word[0] <= 122)
        {
            for (auto &x : word)
            {
                if (x >= 65 && x <= 90)
                {
                    return false;
                }
            }
        }
        else if (word[0] >= 65 && word[0] <= 90)
        {
            if (word[1] >= 65 && word[1] <= 90)
            {
                for (int i = 2; i < n; i++)
                {
                    if (word[i] >= 97 && word[i] <= 122)
                    {
                        return false;
                    }
                }
            }
            else if ((int)word[1] >= 97 && (int)word[1] <= 122)
            {
                for (int i = 2; i < n; i++)
                {
                    if (word[i] >= 65 && word[i] <= 90)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main()
{

    Solution obj;

    cout << obj.detectCapitalUse("USA");

    return 0;
}
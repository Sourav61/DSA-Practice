https : // leetcode.com/contest/weekly-contest-322/problems/circular-sentence/

#include <bits/stdc++.h>
        using namespace std;

class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        int n = sentence.size();

        if (sentence[0] != sentence[n - 1])
        {
            return false;
        }

        for (int i = 0; i < n; i++)
        {
            if (sentence[i] == ' ')
            {
                if (sentence[i - 1] != sentence[i + 1])
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{

    Solution obj;

    cout << obj.isCircularSentence("leetcode exercises sound delightful");

    return 0;
}
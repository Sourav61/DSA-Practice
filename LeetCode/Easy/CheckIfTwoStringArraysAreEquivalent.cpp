// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string s1 = "";
        for (auto x : word1)
        {
            s1 += x;
        }

        string s2 = "";
        for (auto x : word2)
        {
            s2 += x;
        }

        return s1 == s2;
    }
};

int main()
{

    Solution obj;

    vector<string> word1 = {"ab", "c"};

    vector<string> word2 = {"a", "bc"};

    cout << obj.arrayStringsAreEqual(word1, word2);

    return 0;
}
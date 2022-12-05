// https://leetcode.com/problems/determine-if-two-strings-are-close/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        if (n != m)
        {
            return false;
        }

        vector<int> freq1(26), freq2(26), chr1(26), chr2(26);

        for (int i = 0; i < n; i++)
        {
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;

            chr1[word1[i] - 'a'] = 1;
            chr2[word2[i] - 'a'] = 1;
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return (freq1 == freq2) && (chr1 == chr2);
    }
};

int main()
{

    Solution obj;

    cout << obj.closeStrings("abcde", "edcba");

    return 0;
}
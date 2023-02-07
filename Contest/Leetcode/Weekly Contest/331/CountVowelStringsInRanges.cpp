// https://leetcode.com/problems/count-vowel-strings-in-ranges/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isVowel(string x)
    {
        int len = x.size();
        if ((x[0] == 'a' || x[0] == 'e' || x[0] == 'i' || x[0] == 'o' || x[0] == 'u') && (x[len - 1] == 'a' || x[len - 1] == 'e' || x[len - 1] == 'i' || x[len - 1] == 'o' || x[len - 1] == 'u'))
        {
            return 1;
        }

        return 0;
    }

    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        unordered_map<int, int> count;

        vector<int> res;
        int temp = 0;

        for (int i = 0; i < words.size(); i++)
        {
            if (isVowel(words[i]))
            {
                temp++;
            }
            count[i] = temp;
        }

        for (auto &q : queries)
        {
            int cnt = 0;
            int l = q[0] - 1, r = q[1];
            if (q[0] == 0)
            {
                cnt = count[q[1]];
            }
            else
            {
                cnt = (count[q[1]] - count[q[0] - 1]);
            }
            res.push_back(cnt);
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<string> words = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};

    cout << obj.vowelStrings(words, queries);

    return 0;
}
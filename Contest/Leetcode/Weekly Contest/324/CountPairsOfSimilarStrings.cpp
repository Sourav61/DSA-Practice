// https://leetcode.com/problems/count-pairs-of-similar-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int similarPairs(vector<string> &word)
    {
        int ans = 0;

        for (auto &w : word)
        {
            vector<int> arr(26, -1);
            string str = "";
            for (auto &x : w)
            {
                int ch = x - 'a';
                if (arr[ch] == -1)
                {
                    arr[ch] = ch;
                }
            }
            for (auto &x : arr)
            {
                if (x != -1)
                {
                    str += x;
                }
            }
            w = str;
        }

        for (int i = 0; i < word.size(); ++i)
        {
            for (int j = i + 1; j < word.size(); ++j)
            {
                if (word[i] == word[j])
                    ans++;
            }
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<string> word = {"aba", "aabb", "abcd", "bac", "aabc"};

    cout << obj.similarPairs(word);

    return 0;
}
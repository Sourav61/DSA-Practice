// https://leetcode.com/problems/word-ladder-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;

private:
    void dfs(string word, vector<string> &seq)
    {
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mp[word];
        int sz = word.size();
        for (int i = 0; i < sz; i++)
        {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                if (mp.find(word) != mp.end() && mp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push({beginWord});
        b = beginWord;

        mp[beginWord] = 1;
        int sz = beginWord.size();
        st.erase(beginWord);
        while (!q.empty())
        {
            string word = q.front();
            int steps = mp[word];
            q.pop();

            if (word == endWord)
                break;

            for (int i = 0; i < sz; i++)
            {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        q.push(word);
                        st.erase(word);
                        mp[word] = steps + 1;
                    }
                }

                word[i] = original;
            }
        }

        if (mp.find(endWord) != mp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    string beginWord = "";
    string endWord = "";

    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> res = obj.findLadders(beginWord, endWord, wordList);

    return 0;
}
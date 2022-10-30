// https://leetcode.com/problems/words-within-two-edits-of-dictionary/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
    {
        vector<string> ans;

        if (queries[0].length() <= 2)
        {
            return queries;
        }

        for (auto &q : queries)
        {
            for (auto &w : dictionary)
            {
                int cnt = 0;
                for (int i = 0; i < q.length(); i++)
                {
                    if (w[i] == q[i])
                    {
                        cnt++;
                    }
                    if (cnt == q.length() - 2)
                    {
                        break;
                    }
                }

                if (cnt >= q.length() - 2)
                {
                    ans.push_back(q);
                    cnt = 0;
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<string> queries = {"word", "note", "ants", "wood"};
    vector<string> dictionary = {"wood", "joke", "moat"};

    cout << obj.twoEditWords(queries, dictionary);

    return 0;
}
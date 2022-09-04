// https://leetcode.com/problems/top-k-frequent-words/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Comp
    {
        bool operator()(const pair<int, string> &a, const pair<int, string> &b)
        {
            if (a.first == b.first)
                return a.second < b.second;

            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        int n = words.size();

        unordered_map<string, int> mp;
        vector<string> ans;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> minH;

        for (int i = 0; i < n; i++)
        {
            mp[words[i]]++;
        }

        for (auto x : mp)
        {
            minH.push({x.second, x.first});
            if (minH.size() > k)
                minH.pop();
        }

        while (k--)
        {
            ans.push_back(minH.top().second);
            minH.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};

    int k = 2;

    vector<string> ans = obj.topKFrequent(words, k);

    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
// https://leetcode.com/problems/node-with-highest-edge-score/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int edgeScore(vector<int> &edges)
    {
        int n = edges.size();
        long long int score = 0;
        long long int idx = 0;
        unordered_map<long long int, long long int> mp;

        for (long long int i = 0; i < n; i++)
        {
            mp[edges[i]] += i;
        }

        for (auto x : mp)
        {
            if (x.second > score)
            {
                score = x.second;
                idx = x.first;
            }
            else if (x.second == score)
            {
                idx = min(idx, x.first);
            }
        }

        return idx;
    }
};

int main()
{

    Solution obj;

    vector<int> edges = {1, 0, 0, 0, 0, 7, 7, 5};

    cout << obj.edgeScore(edges) << endl;

    return 0;
}
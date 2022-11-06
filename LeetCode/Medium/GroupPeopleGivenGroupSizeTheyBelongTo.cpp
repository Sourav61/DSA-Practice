// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> mp;

        int n = groupSizes.size();

        for (int i = 0; i < n; i++)
        {
            mp[groupSizes[i]].push_back(i);
        }

        for (auto &x : mp)
        {
            int groupNum = x.first;
            vector<int> grouped = x.second;

            vector<int> temp;

            for (auto &x : grouped)
            {
                temp.push_back(x);
                if (temp.size() == groupNum)
                {
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution obj;

    vector<int> groupSizes = {3, 3, 3, 3, 3, 1, 3};

    vector<vector<int>> res = obj.groupThePeople(groupSizes);

    for (auto &v : res)
    {
        for (auto &x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
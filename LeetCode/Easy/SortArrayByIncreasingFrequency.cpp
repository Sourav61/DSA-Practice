// https://leetcode.com/problems/sort-array-by-increasing-frequency/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Comp
    {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {
            if (a.first == b.first)
                return a.second < b.second;

            return a.first > b.first;
        }
    };

    vector<int> frequencySort(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> minH;

        for (auto x : mp)
            minH.push({x.second, x.first});

        while (minH.size() > 0)
        {
            int freq = minH.top().first;
            int ele = minH.top().second;

            for (int i = 0; i < freq; i++)
                ans.push_back(ele);

            minH.pop();
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 1, 2, 2, 2, 3};

    vector<int> ans = obj.frequencySort(nums);

    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
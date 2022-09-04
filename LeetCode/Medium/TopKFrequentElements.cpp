// https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> mp;
        vector<int> ans;
        priority_queue<pair<int, int>> maxH;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for (auto x : mp)
        {
            maxH.push({x.second, x.first});
        }

        while (k--)
        {
            ans.push_back(maxH.top().second);
            maxH.pop();
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 1, 1, 2, 2, 3};

    int k = 2;

    vector<int> ans = obj.topKFrequent(nums, k) << endl;

    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
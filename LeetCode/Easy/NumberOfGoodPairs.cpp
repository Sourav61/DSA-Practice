// https://leetcode.com/problems/number-of-good-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        int res = 0;

        for (auto &x : mp)
        {
            if (x.second > 1)
            {
                int a = x.second;
                res += (a * (a - 1)) / 2;
            }
        }

        return res;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {1, 2, 3, 1, 1, 3};

    cout << obj.numIdenticalPairs(nums);

    return 0;
}
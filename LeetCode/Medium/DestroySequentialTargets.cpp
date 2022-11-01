// https://leetcode.com/problems/destroy-sequential-targets/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int destroyTargets(vector<int> &nums, int space)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        unordered_map<int, int> mpp;

        if (space == 1)
        {
            return nums[0];
        }

        int n = nums.size();
        int maxi = INT_MIN;
        int ans = 0;

        for (auto &x : nums)
        {
            if (mpp[x % space] == 0)
                mpp[x % space] = x;
            mp[x % space]++;
        }

        vector<int> res;

        for (auto &x : mp)
        {
            if (x.second > maxi)
            {
                maxi = x.second;
                ans = mpp[x.first];
            }
            else if (x.second == maxi)
            {
                ans = min(ans, mpp[x.first]);
            }
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {3, 7, 8, 1, 1, 5};

    int space = 2;

    cout << obj.destroyTargets(nums, space);

    return 0;
}
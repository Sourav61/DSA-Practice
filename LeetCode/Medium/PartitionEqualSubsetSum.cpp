// https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;

        if (ind == 0)
            return (nums[0] == target);

        if (dp[ind][target] != -1)
        {
            return dp[ind][target];
        }

        bool notTake = f(ind - 1, target, nums, dp);
        bool take = 0;
        if (nums[ind] <= target)
        {
            take = f(ind - 1, target - nums[ind], nums, dp);
        }

        return dp[ind][target] = take | notTake;
    }

    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (auto x : nums)
        {
            sum += x;
        }
        if (sum % 2 != 0)
            return false;

        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));

        return f(n - 1, sum / 2, nums, dp);
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {1, 5, 11, 5};

    cout << obj.canPartition(nums) << endl;

    return 0;
}
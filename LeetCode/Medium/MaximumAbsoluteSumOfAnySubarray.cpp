// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        // int currSum = 0, maxSum = INT_MIN;

        // int n = nums.size();

        // for (auto x : nums)
        // {
        //     currSum = max(x, currSum + x);
        //     maxSum = max(maxSum, currSum);
        // }

        // currSum = 0;

        // vector<int> dp(nums.size(), 0);

        // for (int i = 0; i < n; i++)
        // {
        //     dp[i] = nums[i];
        // }

        // for (int i = 1; i < n; i++)
        // {
        //     dp[i] = min(dp[i], dp[i - 1] + nums[i]);
        // }

        // int mini = INT_MAX;

        // for (int i = 0; i < n; i++)
        // {
        //     mini = min(mini, dp[i]);
        // }

        // return max(abs(maxSum), abs(mini));

        int currSum = 0, minSum = INT_MAX, maxSum = INT_MIN;
        for (auto x : nums)
            currSum = max(x, currSum + x),
            maxSum = max(maxSum, currSum);

        currSum = 0;

        for (auto x : nums)
            currSum = min(x, currSum + x),
            minSum = min(minSum, currSum);

        return max(abs(maxSum), abs(minSum));
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, -3, 2, 3, -4};

    cout << obj.maxAbsoluteSum(nums) << endl;

    return 0;
}
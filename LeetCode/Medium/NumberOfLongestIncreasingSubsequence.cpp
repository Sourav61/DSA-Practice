// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = 1;

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if (nums[prev] < nums[i] && 1 + dp[prev] == dp[i])
                {
                    cnt[i] += cnt[prev];
                }
            }
            maxi = max(dp[i], maxi);
        }

        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxi)
            {
                res += cnt[i];
            }
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 3, 5, 4, 7};

    cout << obj.findNumberOfLIS(nums);

    return 0;
}
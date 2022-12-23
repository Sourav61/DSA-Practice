// https://leetcode.com/problems/burst-balloons/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;

    int solve(vector<int> &a, int st, int end)
    {
        if (end - st == 1)
            return 0;

        if (dp[st][end] != -1)
        {
            return dp[st][end];
        }

        int ans = 0;

        for (int m = st + 1; m < end; m++)
        {
            int curr = a[st] * a[m] * a[end] + solve(a, st, m) + solve(a, m, end);
            ans = max(ans, curr);
        }

        return dp[st][end] = ans;
    }

    int maxCoins(vector<int> &nums)
    {
        vector<int> a(nums.size() + 2);
        int n = a.size();
        a[0] = a[n - 1] = 1;

        for (int i = 1; i <= n - 2; i++)
        {
            a[i] = nums[i - 1];
        }

        dp.resize(n, vector<int>(n, -1));

        return solve(a, 0, n - 1);
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {3, 1, 5, 8};

    cout << obj.maxCoins(nums);

    return 0;
}
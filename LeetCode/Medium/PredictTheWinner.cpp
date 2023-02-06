// https://leetcode.com/problems/predict-the-winner/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // long long f(int i,int j,vector<int> &nums, int player,vector<vector<int>> &dp){
    //     if(i > j){
    //         return 0;
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     if(player == 1){
    //         return dp[i][j] = max(nums[i] + f(i+1,j,nums,2,dp), nums[j] + f(i,j-1,nums,2,dp));
    //     }else{
    //         return dp[i][j] = min(f(i+1,j,nums,1,dp), f(i, j-1,nums, 1,dp));
    //     }
    // }

    long long f(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        long long maxi = 0;

        long long left = arr[i] + min(f(i + 1, j - 1, arr, dp), f(i + 2, j, arr, dp));
        long long right = arr[j] + min(f(i, j - 2, arr, dp), f(i + 1, j - 1, arr, dp));

        maxi = max(maxi, max(left, right));

        return dp[i][j] = maxi;
    }

    bool PredictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        long long sum = 0;
        for (auto &x : nums)
        {
            sum += (long long)x;
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        long long one = (long long)f(0, n - 1, nums, dp);

        return (one >= sum - one);
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 5, 233, 7};

    cout << obj.PredictTheWinner(nums);

    return 0;
}
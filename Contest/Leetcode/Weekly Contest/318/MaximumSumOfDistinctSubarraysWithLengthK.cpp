// https://leetcode.com/contest/weekly-contest-318/problems/maximum-sum-of-distinct-subarrays-with-length-k/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> mp;

        long long sum = 0, maxi = 0;

        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
            mp[nums[i]]++;
        }

        for (int i = k; i <= n; i++)
        {
            if (mp.size() == k)
            {
                maxi = max(sum, maxi);
            }
            if (i == n)
            {
                break;
            }

            mp[nums[i]]++;
            sum += nums[i];

            if (mp[nums[i - k]] == 1)
            {
                mp.erase(nums[i - k]);
            }
            else
            {
                mp[nums[i - k]]--;
            }
            sum -= nums[i - k];
        }

        return maxi;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
    int k = 3;

    cout << obj.maximumSubarraySum(nums, k);

    return 0;
}
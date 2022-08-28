// https://leetcode.com/problems/subarray-sums-divisible-by-k/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> mp;

        mp[0] = 1;

        int sum = 0, count = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            sum = sum % k;
            if (sum < 0)
            {
                sum += k;
            }

            if (mp.find(sum) != mp.end())
            {
                count += mp[sum];
                mp[sum]++;
            }
            else
            {
                mp[sum] = 1;
            }
        }

        return count;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    cout << obj.subarraysDivByK(nums, k) << endl;

    return 0;
}
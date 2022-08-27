// https://leetcode.com/problems/subarray-sum-equals-k/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();

        if (n == 0)
        {
            return 0;
        }

        unordered_map<int, int> mp;

        int currSum = 0, i = 0, count = 0;

        while (i < n)
        {
            currSum += nums[i];

            if (currSum == k)
            {
                count += 1;
            }

            if (mp.find(currSum - k) != mp.end())
            {
                count += mp[currSum - k];
            }

            mp[currSum] += 1;
            i++;
        }

        return count;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {1, 2, 3};
    int k = 3;

    cout << obj.subarraySum(nums, k) << endl;

    return 0;
}
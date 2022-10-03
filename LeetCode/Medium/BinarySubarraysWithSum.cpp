// https://leetcode.com/problems/binary-subarrays-with-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
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

            if (currSum == goal)
            {
                count += 1;
            }

            if (mp.find(currSum - goal) != mp.end())
            {
                count += mp[currSum - goal];
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

    vector<int> nums = {1, 0, 1, 0, 1};

    int goal = 2;

    cout << obj.numSubarraysWithSum(nums, goal);

    return 0;
}
// https://leetcode.com/problems/minimum-size-subarray-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0, minLength = n + 1, start = 0, end = 0;

        while (end < n)
        {
            sum += nums[end++];

            while (sum >= target && start < n)
            {
                if (end - start < minLength)
                    minLength = end - start;
                sum -= nums[start++];
            }
        }

        return minLength != n + 1 ? minLength : 0;
    }
};

int main()
{

    Solution ojb;

    vector<int> nums = {2, 3, 1, 2, 4, 3};

    int target = 7;

    cout << obj.minSubArrayLen(target, nums);

    return 0;
}
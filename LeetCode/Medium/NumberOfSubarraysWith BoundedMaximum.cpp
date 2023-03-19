// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        int n = nums.size();

        int st = 0, end = 0, res = 0, prev = 0;

        while (end < n)
        {
            if (nums[end] >= left && nums[end] <= right)
            {
                prev = end - st + 1;
                res += prev;
            }
            else if (nums[end] < left)
            {
                res += prev;
            }
            else
            {
                st = end + 1;
                prev = 0;
            }
            end++;
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {2, 1, 4, 3};

    cout << obj.numSubarrayBoundedMax(nums, 2, 3);

    return 0;
}
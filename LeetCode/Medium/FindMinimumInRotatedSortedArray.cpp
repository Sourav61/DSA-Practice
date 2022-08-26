// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0, end = n - 1;

        while (start < end)
        {
            if (nums[start] < nums[end])
                return nums[start];

            int mid = (start + end) / 2;

            if (nums[mid] >= nums[start])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }

        return nums[start];
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {3, 4, 5, 1, 2};

    cout << obj.findMin(nums) << endl;

    return 0;
}
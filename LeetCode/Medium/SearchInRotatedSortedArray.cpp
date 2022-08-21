// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInRotated(vector<int> nums, int key, int left, int right)
    {
        if (left > right)
            return -1;

        int mid = (left + right) / 2;

        if (nums[mid] == key)
            return mid;

        if (nums[left] <= nums[mid])
        {
            if (key >= nums[left] && key <= nums[mid])
                return searchInRotated(nums, key, left, mid - 1);

            return searchInRotated(nums, key, mid + 1, right);
        }

        if (key <= nums[right] && key >= nums[mid])
            return searchInRotated(nums, key, mid + 1, right);

        return searchInRotated(nums, key, left, mid - 1);
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();

        return searchInRotated(nums, target, 0, n - 1);
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    int target = 0;

    cout << obj.search(nums, target) << endl;

    return 0;
}
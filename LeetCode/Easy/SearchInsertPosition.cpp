// https://leetcode.com/problems/search-insert-position/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();

        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low;
    }
};

int main()
{

    Solution obj;
    vector<int> nums = {1, 3, 5, 6};

    cout << obj.searchInsert(nums, 5);

    return 0;
}
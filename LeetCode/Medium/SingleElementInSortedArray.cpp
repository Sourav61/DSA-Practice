// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int res = 0;
        if (n == 1)
        {
            return nums[0];
        }

        int low = 0, high = n - 1, mid = 0;

        if (high == 0)
        {
            return nums[high];
        }
        else if (nums[low] != nums[low + 1])
        {
            return nums[low];
        }
        else if (nums[high] != nums[high - 1])
        {
            return nums[high];
        }

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            else if ((nums[mid] == nums[mid - 1] && mid % 2 != 0) || (nums[mid] == nums[mid + 1] && mid % 2 == 0))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    cout << obj.singleNonDuplicate(nums);

    return 0;
}
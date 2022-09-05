// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<int> ans(2, -1);

        int start = 0, end = n - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] < target)
                start = mid + 1;
            else
            {
                if (nums[mid] == target)
                    ans[0] = mid;
                end = mid - 1;
            }
        }
        start = 0, end = n - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] > target)
                end = mid - 1;
            else
            {
                if (nums[mid] == target)
                    ans[1] = mid;
                start = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {5, 7, 7, 8, 8, 10};

    int target = 8;

    vector<int> ans = obj.searchRange(nums, target);

    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
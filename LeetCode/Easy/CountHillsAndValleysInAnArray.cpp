// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        int last = nums[0];

        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i] == last)
                continue;

            if ((nums[i] < last && nums[i] < nums[i + 1]) || (nums[i] > last && nums[i] > nums[i + 1]))
            {
                count++;
                last = nums[i];
            }
        }

        return count;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {2, 4, 1, 1, 6, 5};

    cout << obj.countHillValley(nums) << endl;

    return 0;
}
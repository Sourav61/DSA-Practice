// https://leetcode.com/problems/find-pivot-index/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0, total = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            if ((i == 0 || i == n - 1) && sum - nums[i] == 0)
            {
                return i;
            }

            if (total == sum - total - nums[i])
            {
                return i;
            }

            total += nums[i];
        }

        return -1;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 7, 3, 6, 5, 6};

    cout << obj.pivotIndex(nums);

    return 0;
}
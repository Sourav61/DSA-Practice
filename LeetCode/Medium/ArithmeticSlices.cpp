// https://leetcode.com/problems/arithmetic-slices/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
        {
            return 0;
        }
        int temp = 0, res = 0;

        for (int i = 1; i < n - 1; i++)
        {
            if ((nums[i] - nums[i - 1]) == (nums[i + 1] - nums[i]))
            {
                temp++;
                res += (temp);
            }
            else
            {
                temp = 0;
            }
        }

        return res;
    }
};

int main()
{

    Solution obj;
    vector<int> nums = {1, 2, 3, 4};

    cout << obj.numberOfArithmeticSlices(nums);

    return 0;
}
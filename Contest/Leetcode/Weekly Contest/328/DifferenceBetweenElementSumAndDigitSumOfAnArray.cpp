// https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int differenceOfSum(vector<int> &nums)
    {
        int ele_sum = 0;
        int dig_sum = 0;

        for (auto &x : nums)
        {
            ele_sum += x;
        }

        for (auto &x : nums)
        {
            while (x)
            {
                dig_sum += x % 10;
                x /= 10;
            }
        }

        return abs(ele_sum - dig_sum);
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 15, 6, 3};

    cout << obj.differenceOfSum(nums);

    return 0;
}
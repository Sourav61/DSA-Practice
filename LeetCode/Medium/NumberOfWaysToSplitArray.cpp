// https://leetcode.com/problems/number-of-ways-to-split-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size();
        long long int leftSum = nums[0], rightSum = 0, count = 0;

        for (int i = 1; i < n; i++)
        {
            rightSum += nums[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (i == 0)
            {
                if (leftSum >= rightSum)
                    count++;
            }
            else
            {
                leftSum += nums[i];
                rightSum -= nums[i];
                if (leftSum >= rightSum)
                {
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {10, 4, -8, 7};

    cout << obj.waysToSplitArray(nums) << endl;

    return 0;
}
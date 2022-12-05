// https://leetcode.com/problems/minimum-average-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        int n = nums.size();

        long long int sum = 0, currSum = 0;

        for (auto &x : nums)
        {
            sum += x;
        }

        int mini = INT_MAX, minIdx = 0;

        for (int i = 0; i < n; i++)
        {
            currSum += nums[i];
            int rightAvg;

            if (i == n - 1)
            {
                rightAvg = 0;
            }
            else
            {
                rightAvg = (sum - currSum) / (n - i - 1);
            }

            if (abs((currSum / (i + 1)) - rightAvg) < mini)
            {
                mini = abs((currSum / (i + 1)) - rightAvg);
                minIdx = i;
            }
        }

        return minIdx;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {2, 5, 3, 9, 5, 3};

    cout << obj.minimumAverageDifference(nums);

    return 0;
}
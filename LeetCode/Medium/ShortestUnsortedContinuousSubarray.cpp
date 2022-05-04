// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        // Using Two Pointer Approach (1st Method)

        int n = nums.size();
        int leastSoFar = INT_MAX, left = 0, right = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            leastSoFar = min(leastSoFar, nums[i]);
            if (leastSoFar != nums[i])
            {
                left = i;
            }
        }
        int maxSoFar = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxSoFar = max(maxSoFar, nums[i]);
            if (maxSoFar != nums[i])
            {
                right = i + 1;
            }
        }
        return right - left;

        // (2nd Method)

        int start = -1, end = -1, max = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (max > nums[i])
            {
                if (start == -1)
                    start = i - 1;
                while (start - 1 >= 0 && nums[start - 1] > nums[i])
                    start--;
                end = i + 1;
            }
            else
                max = nums[i];
        }
        return end - start;
    }
};
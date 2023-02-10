// https://leetcode.com/problems/longest-nice-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int n = nums.size(), j = 0, res = 0, temp = 0;

        for (int i = 0; i < n; i++)
        {
            while ((nums[i] & temp) != 0)
            {
                temp ^= nums[j];
                j++;
            }

            temp |= nums[i];
            res = max(res, i - j + 1);
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 3, 8, 48, 10};

    cout << obj.longestNiceSubarray(nums);

    return 0;
}
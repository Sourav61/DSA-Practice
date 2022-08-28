// https://leetcode.com/problems/subarray-product-less-than-k/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();

        int mult = 1, count = 0, start = 0, end = 0;

        while (end < n)
        {
            mult *= nums[end];

            while (mult > k)
            {
                prod /= nums[start++];
            }

            count = end - start + 1;

            end++;
        }

        return count;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {10, 5, 2, 6};
    int k = 100;

    cout << obj.numSubarrayProductLessThanK(nums, k) << endl;

    return 0;
}
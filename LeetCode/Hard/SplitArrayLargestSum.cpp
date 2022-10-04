// https://leetcode.com/problems/split-array-largest-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int n = nums.size();
        int left = 0, right = 0;

        for (auto x : nums)
        {
            left = max(left, x);
            right += x;
        }

        while (left < right)
        {
            int mid = (left + right) / 2;
            int need = 1, cur = 0;

            for (int i = 0; i < n && need <= m; i++)
            {
                cur += nums[i];
                if (cur > mid)
                {
                    need++;
                    cur = nums[i];
                }
            }

            if (need > m)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {7, 2, 5, 10, 8};
    int m = 2;

    cout << obj.splitArray(nums, m) << endl;

    return 0;
}
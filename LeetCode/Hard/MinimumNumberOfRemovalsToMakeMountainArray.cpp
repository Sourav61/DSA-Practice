// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();

        int maxi = 0;

        vector<int> inc(n);

        for (int i = 0; i < n; i++)
        {
            inc[i] = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] < nums[i] && inc[j] + 1 > inc[i])
                {
                    inc[i] = inc[j] + 1;
                }
            }
        }

        vector<int> dec(n);

        for (int i = n - 1; i >= 0; i--)
        {
            dec[i] = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] < nums[i] && dec[j] + 1 > dec[i])
                {
                    dec[i] = dec[j] + 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (inc[i] > 1 && dec[i] > 0)
            {
                maxi = max(maxi, inc[i] + dec[i]);
            }
        }

        return n - maxi;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {2, 1, 1, 5, 6, 2, 3, 1};

    cout << obj.minimumMountainRemovals(nums);

    return 0;
}
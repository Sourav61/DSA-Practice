// https://leetcode.com/problems/maximum-product-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int r, maxi, mini;

        r = maxi = mini = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (nums[i] < 0)
                swap(maxi, mini);

            maxi = max(nums[i], maxi * nums[i]);
            mini = min(nums[i], mini * nums[i]);

            r = max(r, maxi);
        }
        return r;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {2, 3, -2, 4};

    cout << obj.maxProduct(nums) << endl;

    return 0;
}
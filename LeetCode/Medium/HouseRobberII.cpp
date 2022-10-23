// https://leetcode.com/problems/house-robber-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums)
    {
        int n = nums.size();
        int prev2 = 0;
        int prev = nums[0];

        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
            {
                take += prev2;
            }

            int ntake = 0 + prev;

            int curi = max(take, ntake);

            prev2 = prev;
            prev = curi;
        }

        return prev;
    }

    int rob(vector<int> &nums)
    {
        vector<int> nfirst, nlast;

        int n = nums.size();

        if (n == 1)
            return nums[0];

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                nfirst.push_back(nums[i]);

            if (i != n - 1)
                nlast.push_back(nums[i]);
        }

        return max(solve(nfirst), solve(nlast));
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {2, 3, 2};

    cout << obj.rob(nums);

    return 0;
}
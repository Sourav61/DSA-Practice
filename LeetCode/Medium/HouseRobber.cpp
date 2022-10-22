// https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;
            int npick = 0 + prev;
            int curi = max(pick, npick);

            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 2, 3, 1};

    cout << obj.rob(nums);

    return 0;
}
// https://leetcode.com/problems/jump-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int reachable = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (reachable < i)
            {
                return false;
            }

            reachable = max(reachable, nums[i] + i);
        }

        return true;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {2, 3, 1, 1, 4};

    cout << obj.canJump(nums);

    return 0;
}
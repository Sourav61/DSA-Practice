// https://leetcode.com/problems/move-zeroes/description/

#include <bitsstdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int j = 0, n = nums.size();

        for (auto &x : nums)
        {
            if (x != 0)
            {
                nums[j++] = x;
            }
        }

        while (j < n)
        {
            nums[j++] = 0;
        }
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {0, 1, 0, 3, 12};

    cout << obj.moveZeroes(nums);

    return 0;
}
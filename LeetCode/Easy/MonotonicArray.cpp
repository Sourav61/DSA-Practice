// https://leetcode.com/problems/monotonic-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        bool inc = true, dec = true;
        for (int i = 1; i < nums.size(); ++i)
        {
            inc = inc & (nums[i - 1] <= nums[i]);
            dec = dec & (nums[i - 1] >= nums[i]);
        }
        return inc || dec;
    }
};

int main()
{

    return 0;
}
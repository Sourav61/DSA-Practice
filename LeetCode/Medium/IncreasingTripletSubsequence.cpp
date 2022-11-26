// https://leetcode.com/problems/increasing-triplet-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int mini_1 = INT_MAX, mini_2 = INT_MAX;

        if (nums.size() < 3)
            return false;

        for (int &num : nums)
        {
            if (num <= mini_1)
                mini_1 = num;
            else if (num <= mini_2)
                mini_2 = num;
            else
                return true;
        }

        return false;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 2, 3, 4, 5};

    cout << obj.increasingTriplet(nums);

    return 0;
}
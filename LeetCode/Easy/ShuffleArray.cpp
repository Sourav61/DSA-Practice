// https://leetcode.com/problems/shuffle-the-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        int i = 0;

        vector<int> res;

        while (i < n)
        {
            res.push_back(nums[i]);
            res.push_back(nums[i + n]);
            i++;
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {2, 5, 1, 3, 4, 7};

    cout << obj.shuffle(nums, 3);

    return 0;
}
// https://leetcode.com/problems/single-number/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;

        for (auto x : nums)
            ans ^= x;

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {2, 1, 2};

    cout << obj.singleNumber(nums) << endl;

    return 0;
}
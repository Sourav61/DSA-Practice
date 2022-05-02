// https://leetcode.com/problems/sort-array-by-parity/
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool Compare(int a, int b)
    {
        if (a % 2 == 0 && b % 2 != 0)
            return true;
        else
            return false;
    }
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), Compare);
        return nums;
    }
};

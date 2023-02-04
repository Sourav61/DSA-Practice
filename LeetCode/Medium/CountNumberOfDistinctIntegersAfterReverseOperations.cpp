// https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverseInt(int n)
    {
        int res = 0;
        while (n)
        {
            res = res * 10 + n % 10;
            n /= 10;
        }

        return res;
    }

    int countDistinctIntegers(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
            int temp = reverseInt(nums[i]);
            mp[temp]++;
        }

        return mp.size();
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 13, 10, 12, 31};

    cout << obj.countDistinctIntegers(nums);

    return 0;
}
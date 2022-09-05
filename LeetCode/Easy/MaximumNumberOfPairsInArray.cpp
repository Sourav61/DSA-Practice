// https://leetcode.com/problems/maximum-number-of-pairs-in-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        int leftOver = 0;
        int pairs = 0;
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for (auto i : mp)
        {
            pairs += i.second / 2;
            if (i.second % 2 != 0)
            {
                leftOver++;
            }
        }

        return {pairs, leftOver};
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 3, 2, 1, 3, 2, 2};

    vector<int> res = obj.numberOfPairs(nums);

    for (auto x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}
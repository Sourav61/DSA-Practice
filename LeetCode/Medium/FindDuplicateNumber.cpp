// https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // int n = nums.size();

        // unordered_map<int, int> mp;

        // for (int i = 0; i < n; i++)
        // {
        //     mp[nums[i]]++;
        // }

        // for (auto x : mp)
        // {
        //     if (x.second > 1)
        //     {
        //         return x.first;
        //     }
        // }

        // return -1;

        int n = nums.size();

        int dup = -1;

        for (int i = 0; i < n; i++)
        {
            int cur = abs(nums[i]);
            if (nums[cur] < 0)
            {
                dup = cur;
                break;
            }
            nums[cur] *= -1;
        }

        for (auto &num : nums)
            num = abs(num);

        return dup;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 1, 1, 1};

    cout << obj.findDuplicate(nums);

    return 0;
}
// https://leetcode.com/problems/contains-duplicate-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (mp.find(nums[i]) != mp.end())
            {
                if (abs(mp[nums[i]] - i) <= k)
                    return true;
                else
                    mp[nums[i]] = i;
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    cout << obj.containsNearbyDuplicate(nums, k) << endl;

    return 0;
}
// https://leetcode.com/problems/contains-duplicate-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        int n = nums.size();

        if (n == 0 || k < 0 || t < 0)
            return false;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; ++i)
        {
            int bucket = nums[i] / ((long)t + 1);
            if (nums[i] < 0)
                --bucket;

            if (mp.find(bucket) != mp.end())
                return true;
            else
            {
                mp[bucket] = nums[i];
                if (mp.find(bucket - 1) != mp.end() && (long)nums[i] - mp[bucket - 1] <= t)
                    return true;
                if (mp.find(bucket + 1) != mp.end() && (long)mp[bucket + 1] - nums[i] <= t)
                    return true;

                if (mp.size() > k)
                {
                    int key = nums[i - k] / ((long)t + 1);

                    if (nums[i - k] < 0)
                        --key;

                    mp.erase(key);
                }
            }
        }

        return false;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 2, 3, 1};

    cout << obj.containsNearbyAlmostDuplicate(nums, k, t) << endl;

    return 0;
}
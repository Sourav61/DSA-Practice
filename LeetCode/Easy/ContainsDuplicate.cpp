#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (mp.find(nums[i]) != mp.end())
            {
                return true;
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

    cout << obj.containsDuplicate(nums) << endl;

    return 0;
}
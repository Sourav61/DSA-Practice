// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();

        int idx = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[idx] != nums[i])
            {
                idx++;
                nums[idx] = nums[i];
            }
        }

        return idx + 1;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 1, 2};

    cout << obj.removeDuplicates(nums);

    return 0;
}
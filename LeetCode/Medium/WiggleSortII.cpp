// https://leetcode.com/problems/wiggle-sort-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(nums);
        sort(ans.begin(), ans.end());
        int k = 1;
        int i = n - 1;
        while (k < n)
        {
            nums[k] = ans[i];
            i--;
            k = k + 2;
        }
        int j = 0;
        while (j < n)
        {
            nums[j] = ans[i];
            i--;
            j = j + 2;
        }
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 5, 1, 1, 6, 4};

    obj.wiggleSort();

    return 0;
}
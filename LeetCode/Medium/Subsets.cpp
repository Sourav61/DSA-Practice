// https://leetcode.com/problems/subsets/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void findCombi(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
    {
        ans.push_back(ds);

        for (int i = ind; i < nums.size(); i++)
        {
            if (i != ind && nums[i] == nums[i - 1])
                continue;
            ds.push_back(nums[i]);
            findCombi(i + 1, nums, ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombi(0, nums, ds, ans);
        return ans;
    }
};
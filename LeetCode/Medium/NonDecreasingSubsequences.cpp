// https://leetcode.com/problems/non-decreasing-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<vector<int>> hash;

    void f(int i, vector<int> &nums, int n, vector<int> &temp)
    {
        if (i == n && temp.size() <= 1)
        {
            return;
        }
        if (i == n)
        {
            hash.insert(temp);
            return;
        }

        if (temp.size() == 0 || temp.back() <= nums[i])
        {
            temp.push_back(nums[i]);
            f(i + 1, nums, n, temp);
            temp.pop_back();
        }
        f(i + 1, nums, n, temp);
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;
        f(0, nums, n, temp);

        vector<vector<int>> res(hash.begin(), hash.end());

        return res;
    };
};

int main()
{

    Solution obj;

    vector<int> nums = {4, 6, 7, 7};

    vector<vector<int>> res = obj.findSubsequences(nums);

    for (auto &v : res)
    {
        for (auto &x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
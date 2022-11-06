// https://leetcode.com/contest/weekly-contest-318/problems/apply-operations-to-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                continue;
            }
            else
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                res.push_back(nums[i]);
            }
            else
            {
                cnt++;
            }
        }

        while (cnt--)
        {
            res.push_back(0);
        }

        return res;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {1, 2, 2, 1, 1, 0};

    cout << obj.applyOperations(nums);

    return 0;
}
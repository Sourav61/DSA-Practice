// https://leetcode.com/problems/set-mismatch/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();

        int dup = -1, missing = 1;

        for (int i = 0; i < n; i++)
        {
            int cur = abs(nums[i]) - 1;

            if (nums[cur] < 0)
            {
                dup = abs(cur + 1);
            }
            else
            {
                nums[cur] *= -1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                missing = i + 1;
            }
        }

        return {dup, missing};
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 2, 2, 4};

    vector<int> res = obj.findErrorNums(nums);

    for (auto x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}
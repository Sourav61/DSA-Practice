// https://leetcode.com/problems/4sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {

        vector<vector<int>> res;

        if (nums.empty())
            return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {

            long long target_3 = (long long)target - (long long)nums[i];

            for (int j = i + 1; j < nums.size(); j++)
            {

                long long target_2 = target_3 - (long long)nums[j];

                int front = j + 1;
                int back = nums.size() - 1;

                while (front < back)
                {

                    int two_sum = nums[front] + nums[back];

                    if (two_sum < target_2)
                        front++;

                    else if (two_sum > target_2)
                        back--;

                    else
                    {

                        vector<int> quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];
                        res.push_back(quad);

                        while (front < back && nums[front] == quad[2])
                            ++front;

                        while (front < back && nums[back] == quad[3])
                            --back;
                    }
                }

                while (j + 1 < nums.size() && nums[j + 1] == nums[j])
                    ++j;
            }

            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                ++i;
        }

        return res;
    }
};
int main()
{

    Solution obj;

    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> ans = obj.fourSum(nums, target);

    for (vector<int> v : ans)
    {
        for (auto x : v)
            cout << v << " ";
        cout << endl;
    }
    return 0;
}
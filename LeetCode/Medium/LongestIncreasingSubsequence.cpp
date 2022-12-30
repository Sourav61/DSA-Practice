// https://leetcode.com/problems/longest-increasing-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> curr(n + 1, 0), ahead(n + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev = ind - 1; prev >= -1; prev--)
            {
                int len = 0 + ahead[prev + 1];

                if (prev == -1 || nums[ind] > nums[prev])
                {
                    len = max(len, 1 + ahead[ind + 1]);
                }

                curr[prev + 1] = len;
            }
            ahead = curr;
        }

        return curr[0];
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << obj.lengthOfLIS(nums);

    return 0;
}
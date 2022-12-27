// https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = nums[i] + nums[i - 1];
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int idx = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
            ans.push_back(idx);
        }
        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {4, 5, 2, 1};
    vector<int> queries = {3, 10, 21};

    cout << obj.answerQueries(nums, queries);

    return 0;
}
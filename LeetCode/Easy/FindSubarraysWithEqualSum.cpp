// https://leetcode.com/problems/find-subarrays-with-equal-sum/

static int fast_io = []()
{ std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution
{
public:
    bool findSubarrays(vector<int> &nums)
    {

        unordered_set<int> check;

        for (int i = 1; i < size(nums); ++i)
        {
            const int sum = nums[i - 1] + nums[i];
            auto [x, inserted] = check.insert(sum);
            if (!inserted)
                return true;
        }
        return false;
    }
};
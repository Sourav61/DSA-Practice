// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int ans = 0, mod = 1e9 + 7;

        int l = 0;
        int r = n - 1;

        vector<int> pows(n, 1);

        for (int i = 1; i < n; ++i)
            pows[i] = pows[i - 1] * 2 % mod;

        while (l <= r)
        {
            if (nums[l] + nums[r] > target)
            {
                r--;
            }
            else
            {
                ans = (ans + (long long int)pows[r - l]) % mod;
                l++;
            }
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {3, 5, 6, 7};
    int target = 9;

    cout << obj.numSubseq(nums, target);

    return 0;
}
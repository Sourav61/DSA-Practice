// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        long long ans = 0;

        vector<long long> pre(n, 0);

        long long int temp = 0;

        for (int i = 0; i < n; i++)
        {
            temp += nums[i];
            pre[i] = temp;
        }

        for (long long i = 0; i < n; i++)
        {
            long long s = 1, e = (i + 1);
            long long int curr = 0;

            while (s <= e)
            {
                long long int mid = (s + e) / 2;
                long long int temp = pre[i];

                if (i - mid >= 0)
                {
                    temp -= pre[i - mid];
                }

                temp = temp * mid;

                if (temp < k)
                {
                    curr = mid;
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            ans += curr;
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {2, 1, 4, 3, 5};
    int k = 10;

    cout << obj.countSubarrays(nums, k);

    return 0;
}
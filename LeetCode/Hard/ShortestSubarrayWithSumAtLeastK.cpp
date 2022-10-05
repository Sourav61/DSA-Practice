// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();

        deque<pair<long long int, long long int>> dq;

        long long sum = 0;
        long long ans = INT_MAX;

        for (long long i = 0; i < n; i++)
        {
            sum += nums[i];

            if (sum >= k)
                ans = min(ans, i + 1);

            pair<long long, long long> curr = {INT_MIN, INT_MIN};

            while (!dq.empty() && sum - dq.front().second >= k)
            {
                curr = dq.front();
                dq.pop_front();
            }

            if (curr.second != INT_MIN)
                ans = min(ans, i - curr.first);

            while (!dq.empty() && sum <= dq.back().second)
                dq.pop_back();

            dq.push_back({i, sum});
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {77, 19, 35, 10, -14};
    int k = 19;

    cout << obj.shortestSubarray(nums, k) << endl;

    return 0;
}
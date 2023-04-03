// https://leetcode.com/problems/number-of-zero-filled-subarrays/description/

#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long res = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                long long temp = 0;
                while (i < n && nums[i] == 0)
                {
                    temp++;
                    res += temp;
                    i++;
                }
            }
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 3, 0, 0, 2, 0, 0, 4};

    cout << obj.zeroFilledSubarray(nums);

    return 0;
}
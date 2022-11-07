// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int n = nums.size();

        int ans = 0;

        for (int i = 0; i < n;)
        {
            int s = i;

            while (s < n && nums[s] == 0)
                s++;

            int e = s;
            int cnt = 0;
            int sn = -1, en = -1;
            while (e < n && nums[e] != 0)
            {
                if (nums[e] < 0)
                {
                    cnt++;
                    if (sn == -1)
                    {
                        sn = e;
                    }
                    en = e;
                }
                e++;
            }
            if (cnt % 2 == 0)
            {
                ans = max(ans, e - s);
            }
            else
            {
                if (sn != -1)
                {
                    ans = max(ans, e - sn - 1);
                }
                if (en != -1)
                {
                    ans = max(ans, en - s);
                }
            }

            i = e + 1;
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, -2, -3, 4};

    cout << obj.getMaxLen(nums);

    return 0;
}
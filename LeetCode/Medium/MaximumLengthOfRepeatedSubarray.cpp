// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for (int j = 0; j <= m; j++)
        {
            prev[j] = 0;
        }

        int maxLen = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    cur[j] = 1 + prev[j - 1];
                    maxLen = max(maxLen, cur[j]);
                }
                else
                {
                    cur[j] = 0;
                }
            }
            prev = cur;
        }

        return maxLen;
    }
};

int main()
{
    Solution obj;

    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};

    cout << obj.findLength(nums1, nums2);

    return 0;
}
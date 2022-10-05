// https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int a = m - 1;
        int b = n - 1;
        int i = m + n - 1;

        while (a >= 0 && b >= 0)
        {
            if (nums1[a] > nums2[b])
                nums1[i--] = nums1[a--];
            else
                nums1[i--] = nums2[b--];
        }

        while (b >= 0)
            nums1[i--] = nums2[b--];
    }
};

int main()
{

    Solution obj;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    obj.merge(nums1, m, nums2, n);

    return 0;
}
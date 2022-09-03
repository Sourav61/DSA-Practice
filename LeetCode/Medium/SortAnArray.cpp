// https://leetcode.com/problems/sort-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void heapify(vector<int> &nums, int n, int i)
    {
        int maxIdx = i;

        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && nums[l] > nums[maxIdx])
            maxIdx = l;

        if (r < n && nums[r] > nums[maxIdx])
            maxIdx = r;

        if (maxIdx != i)
        {
            swap(nums[i], nums[maxIdx]);

            heapify(nums, n, maxIdx);
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(nums, n, i);
        }

        for (int i = n - 1; i > 0; i--)
        {
            swap(nums[0], nums[i]);

            heapify(nums, i, 0);
        }

        return nums;
    }
};

int main()
{

    Solution obj;

    vector int nums = {5, 2, 3, 1};

    obj.sortArray(nums);

    for (auto x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minH;

        for (int i = 0; i < nums.size(); i++)
        {
            minH.push(nums[i]);

            if (minH.size() > k)
            {
                minH.pop();
            }
        }
        return minH.top();
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << obj.findKthLargest(nums, k) << endl;

    return 0;
}
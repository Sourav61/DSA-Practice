// https://leetcode.com/problems/maximum-product-of-three-numbers/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());

        long int neg = nums[0] * nums[1] * nums[n - 1];
        long int pos = nums[n - 3] * nums[n - 1] * nums[n - 2];

        return max(neg, pos);
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {1, 2, 3};

    cout << obj.maximumProduct(nums) << endl;

    return 0;
}
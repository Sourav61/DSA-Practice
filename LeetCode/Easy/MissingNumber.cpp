// https://leetcode.com/problems/missing-number/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // int n = nums.size();
        // int missing = 0;

        // for(int i=0;i<n;i++){
        //     if(nums[i] == 0){
        //         nums[i] = n+1;
        //         nums[0] *= -1;
        //     }
        // }

        // for(int i=0;i<n;i++){
        //     if(abs(nums[i]) < n){
        //         nums[abs(nums[i])] *= -1;
        //     }
        // }

        // for(int i=0;i<n;i++){
        //     if(nums[i] > 0){
        //         return i;
        //     }
        // }

        // return n;

        int n = nums.size();
        for (int i = 0; i < n; i++)
            while (nums[i] >= 0 && nums[i] < n && nums[nums[i]] != nums[i])
                swap(nums[i], nums[nums[i]]);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i)
                return i;
        }
        return n;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {3, 0, 1};

    cout << obj.missingNumber(nums);

    return 0;
}
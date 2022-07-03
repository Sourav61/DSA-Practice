// https://leetcode.com/problems/sort-array-by-parity-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        
        int even = 0;
        int odd = 1;

        while(even < n && odd < n){
            if((nums[even] % 2) && !(nums[odd]%2)){
                swap(nums[even], nums[odd]);
            }

            if(!(nums[even] % 2))
                even += 2;
            if(nums[odd] % 2)
                odd += 2;
        }

        return nums;
    }
};

int main(){
    Solution obj;

    vector<int> nums = {4,2,5,7};

    cout<<obj.sortArrayByParityII(nums);

    return 0;
}
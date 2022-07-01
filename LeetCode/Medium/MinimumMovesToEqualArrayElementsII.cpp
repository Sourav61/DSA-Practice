// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

#include<bits/std++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int a = n/2;
        
        int sum = 0;
        for(auto x : nums){
            if(x-nums[a] < 0){
                sum += (nums[a] - x);
            }else{
                sum += (x - nums[a]);                
            }
        }

        return sum;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {1,2,3};

    cout<<obj.minMoves2(nums)<<endl;

    return 0;
}
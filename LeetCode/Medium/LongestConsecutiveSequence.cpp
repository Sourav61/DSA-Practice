// https://leetcode.com/problems/longest-consecutive-sequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        int maxi = 0;
        int ans = 1;

        sort(nums.begin(),nums.end());
        
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]){
                continue;
            }else if(nums[i] - nums[i-1] == 1){
                ans++;
            }else{
                maxi = max(ans, maxi);
                ans = 1;
            }
        }

        return max(ans, maxi);
    }
};

int main(){

    Solution obj;

    vector<int> nums = {100,4,200,1,3,2};

    cout<<obj.longestConsecutive(nums);
    
    return 0;
}
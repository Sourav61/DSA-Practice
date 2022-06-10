// https://leetcode.com/problems/max-consecutive-ones/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int ans= 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                count++;
            }else{
                count = 0;
            }
            ans = max(ans,count);
        }
        
        return ans;
    }
};

int main(){
    Solution obj;

    vector<int> nums = {1,1,0,1,1,1};

    int ans = obj.findMaxConsecutiveOnes(nums);

    cout<<ans<<endl;

    return 0;
}
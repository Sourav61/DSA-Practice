// https://leetcode.com/problems/3sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            
            int target = -nums[i];
            if(target < 0)
            {
                break;
            }
            int lo = i + 1, hi = n - 1;
            while(lo<hi){
                int sum = nums[lo] + nums[hi];
                
                if(sum<target){
                    lo++;
                }else if(sum>target){
                    hi--;
                }
                else{
                    vector<int> triplet = {nums[i],nums[lo],nums[hi]};
                    ans.push_back(triplet);
                    while (lo < hi && nums[lo] == triplet[1]){
                        lo++;
                    }
                    
                    while (lo < hi && nums[hi] == triplet[2]){
                        hi--;
                    }
                }

            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;
        }
        
        return ans;
    }
};

int main(){
    int n;
    Solution obj;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> res = obj.threeSum(nums);

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<res[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}
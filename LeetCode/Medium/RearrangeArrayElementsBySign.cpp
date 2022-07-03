// https://leetcode.com/problems/rearrange-array-elements-by-sign/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //         int n = nums.size();

        //         vector<int> ans;

        //         vector<int> pos;
        //         vector<int> neg;

        //         for(int i=0;i<n;i++){
        //             if(nums[i] > 0){
        //                 pos.push_back(nums[i]);
        //             }else{
        //                 neg.push_back(nums[i]);
        //             }
        //         }

        //         for(int i=0;i<n;i++){
        //             if(i%2 == 0){
        //                 ans.push_back(pos[i/2]);
        //             }else{
        //                 ans.push_back(neg[i/2]);
        //             }
        //         }

        //         return ans;
        
        int n = nums.size();

        vector<int> ans(n,0);
        
        int pos = 0;
        int neg = 1;

        for(auto x : nums){
            if(x > 0){
                ans[pos] = x;
                pos += 2;
            }
            
            if(x < 0){
                ans[neg] = x;
                neg+=2;
            }
        }

        return ans;
    }
};

int main(){

    Solution obj;


 
    return 0;
}
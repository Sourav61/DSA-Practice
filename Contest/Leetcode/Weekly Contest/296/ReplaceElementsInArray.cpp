// https://leetcode.com/contest/weekly-contest-296/problems/replace-elements-in-an-array/.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        // =====================           Approach-1           ==================================
        
        // int n = nums.size();
        // int m = operations.size();
        // for(int i = 0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(nums[i] == operations[j][0]){
        //             // cout<<nums[i]<<" "<<operations[j][0]<<" "<<operations[j][1]<<endl;
        //             nums[i] = operations[j][1];
        //         }
        //     }
        // }

        // return nums;


        // =====================           Approach-2(Optimized Using 2 maps)          ==================================


        map<int,int> m1,m2;

        for(int i=0;i<nums.size();i++){
            m1[nums[i]] = i+1;
            m2[i+1] = nums[i];
        }

        for(auto x: operations){
            int value = x[0], new_value = x[1];
            int index = m1[value];

            m2[index] = new_value;

            m1.erase(value);
            m1[new_value] = index;
        }

        vector<int> ans;

        for(auto x:m2){
            ans.push_back(x.second);
        }

        return ans;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {1,2,4,6};

    vector<vector<int>> operations = {{1,3}, {4,7}, {6,1}};

    vector<int> ans = obj.arrayChange(nums,operations);

    for(auto x : ans){
        cout<<x<<" ";
    }cout<<endl;

    return 0;
}
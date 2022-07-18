// https://leetcode.com/problems/two-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> v;

        for(int i=0;i<nums.size();i++){
            int toFind = target - nums[i];

            if(mpp.find(toFind) != mpp.end()){
                v.push_back(mpp[toFind]);
                v.push_back(i);
                return v;
            }

            mpp[nums[i]] = i;        
        }

        return v;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {2,7,11,15};

    vector<int> ans = obj.twoSum(nums, 9);

    for(auto x : ans)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}
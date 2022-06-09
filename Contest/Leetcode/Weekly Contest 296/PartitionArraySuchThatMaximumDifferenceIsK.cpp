// https://leetcode.com/contest/weekly-contest-296/problems/partition-array-such-that-maximum-difference-is-k/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int count = 0;
        int mini = INT_MAX;

        sort(nums.begin(),nums.end());
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(mini == INT_MAX){
                mini = nums[i];
                count++;
            }
            else{
                if(nums[i] - mini > k){
                    mini = nums[i];
                    count++;
                }
            }
        }

        return count;
    }
};

int main(){

    Solution obj;
    int k;

    vector<int> nums = {3,6,1,2,5};

    int ans = obj.partitionArray(nums,2);

    cout<<ans;

    return 0;
}
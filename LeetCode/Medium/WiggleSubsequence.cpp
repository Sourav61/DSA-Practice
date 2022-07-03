// https://leetcode.com/problems/wiggle-subsequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();

        if(n==0)
            return 0;

        vector<int> pos(n, 0);
        vector<int> neg(n, 0);

        pos[0] = 1;
        neg[0] = 1;

        for(int i=0;i<n;i++){
            if(nums[i] > nums[i-1]){
                pos[i] = neg[i-1] + 1;
                neg[i] = neg[i-1];
            }else if(nums[i] < nums[i-1]){
                neg[i] = pos[i-1] + 1;
                pos[i] = pos[i-1];
            }else{
                pos[i] = pos[i-1];
                neg[i] = neg[i-1];
            }
        }

        return max(pos[n-1], neg[n-1]);
    }
};

int main(){

    Solution obj;



    return 0;
}
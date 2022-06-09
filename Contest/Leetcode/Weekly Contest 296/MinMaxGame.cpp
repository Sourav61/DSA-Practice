// https://leetcode.com/contest/weekly-contest-296/problems/min-max-game//

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> num(nums.size()/2 , 0);
        
        for(int i=0;i<(nums.size())/2; i++){
            if(i%2==0){
                num[i] = min(nums[2 * i], nums[(2 * i) + 1]);
            }else{
                num[i] = max(nums[2 * i], nums[(2 * i) + 1]);
            }
        }
        
        return minMaxGame(num);
    }
};

int main(){
    Solution obj;

    vector<int> nums;

    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(8);
    nums.push_back(2);
    nums.push_back(2);

    cout<<obj.minMaxGame(nums);

    return 0;
}
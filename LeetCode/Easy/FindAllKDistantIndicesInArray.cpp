// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> temp;
        set<int> v;
        for(int i=0;i<n;i++){
            if(nums[i] == key){
                temp.push_back(i);
            }
        }
        
        for(auto x : temp){
            for(int i=0;i<n;i++){
                if(abs(i-x) <= k)
                    v.insert(i);
            }
        }
        vector<int> res;

        for(auto x : v){
            res.push_back(x);
        }cout<<endl;

        return res;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {3,4,9,1,3,9,5};

    vector<int> ans = obj.findKDistantIndices(nums, 9,1);

    for(auto x : ans)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}
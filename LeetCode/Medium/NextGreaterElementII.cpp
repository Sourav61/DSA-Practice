// https://leetcode.com/problems/next-greater-element-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n,-1);
        
        stack<int> st;

        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }

            if(i<n){
                if(!st.empty()){
                    ans[i] = st.top();
                }
            }

            st.push(nums[i%n]);
        }

        return ans;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {1,2,1};

    vector<int> res = obj.nextGreaterElements(nums);

    for(auto x : res){
        cout<<x<<" ";
    }cout<<endl;

    return 0;
}
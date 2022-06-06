// https://leetcode.com/problems/sliding-window-maximum/submissions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front() == i-k)
                dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        
        return ans;
    }
};

int main(){
    Solution obj;
    int n,k;
    cin>>n>>k;
    
    vector<int> nums(n);

    for(int i = 0;i<n;i++) 
	    cin >> nums[i];

    Solution ob;
    vector <int> res = ob.maxSlidingWindow(nums, k);
    for (int i = 0; i < res.size (); i++) 
        cout << res[i] << " ";
    cout << endl;
}
// https://leetcode.com/problems/trapping-rain-water/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left = 0, right = n-1;
        int res = 0;
        int leftmax = 0, rightmax = 0;
        while(left<=right){
            if(height[left] <= height[right]){
                if(height[left] >= leftmax)
                    leftmax = height[left];

                else
                    res += leftmax-height[left];

                left++;
            }else{
                if(height[right] >= rightmax)
                    rightmax = height[right];

                else   
                    res += rightmax-height[right];
                
                right--;
            }
        }

        return res;
    }
};

int main(){
    Solution obj;
    int arr[] = {4,2,0,3,2,5};
    vector<int> height;
    for(int i=0;i<6;i++){
        height.push_back(arr[i]);
    }
    int ans = obj.trap(height);

    cout<<ans<<endl;

    return 0;
}
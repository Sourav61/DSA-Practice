// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // ===================     Approach-1       ==========================
        
        // int n = heights.size();
        // int i = 0, ans = 0;
        // stack<int> st;
        // heights.push_back(0);

        // while(i<n){
        //     while(!st.empty() && heights[st.top()] > heights[i]){
        //         int t = st.top();
        //         int h = heights[t];
        //         st.pop();
        //         if(st.empty()){
        //             ans = max(ans, h*i);
        //         }else{
        //             int len = i - st.top() - 1;
        //             ans = max(ans, h*len);
        //         }
        //     }
        // }

        // ==============================          Approach-2        =====================================

        int n = heights.size();
        stack<int> st;

        int leftsmall[n], rightsmall[n];

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty())
                leftsmall[i] = 0;
            else
                leftsmall[i] = st.top() + 1;
            st.push(i);
        }

        while(!st.empty())
            st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty())
                rightsmall[i] = n-1;
            else
                rightsmall[i] = st.top() - 1;
            
            st.push(i);
        }

        int maxA = 0;

        for(int i=0;i<n;i++){
            maxA = max(maxA, heights[i] * (rightsmall[i]-leftsmall[i]+1));
        }

        return maxA;
    }
};

int main(){
    Solution obj;


    return 0;
}
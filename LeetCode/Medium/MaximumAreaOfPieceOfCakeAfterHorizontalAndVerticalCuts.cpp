// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());

        const long long int mod = 1000000007;

        int maxH = 0, maxV = 0;

        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);

        int hSize = horizontalCuts.size();
        int vSize = verticalCuts.size();

        vector<int> heights = {horizontalCuts[0]};
        vector<int> width = {verticalCuts[0]};
        
        for (int i=1; i<hSize; i++) {
            heights.push_back(horizontalCuts[i]-horizontalCuts[i-1]);
        }
        heights.push_back(h-horizontalCuts[hSize-1]);
        
        for (int i=1; i<vSize; i++) {
            width.push_back(verticalCuts[i]-verticalCuts[i-1]);
        }
        width.push_back(w-verticalCuts[vSize-1]);

        long long int a = *max_element(heights.begin(), heights.end());
        long long int b = *max_element(width.begin(), width.end());

        return (a%mod*b%mod);
    }
};

int main(){

    Solution obj;

    return 0;
}
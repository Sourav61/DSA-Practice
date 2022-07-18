// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt[101] = {};
        int res = 0;
        for (auto x : nums)
            cnt[x]++;
        for (int i = k + 1; i < 101; ++i)
            res += cnt[i] * cnt[i - k];
        return res;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {1,2,2,1};

    cout<<obj.countKDifference(nums, 1);

    return 0;
}
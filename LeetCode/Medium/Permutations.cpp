// https://leetcode.com/problems/permutations/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Approach-1 (Uses extra space by using an array for counting freq)
    // Time Complexity => O(N!)*O(N)
    // Space Complexity => O(N)*O(N)
    // Auxilliary Space => O(N)

    // private:
    //      void findPermute(vector<int> &ds,vector<int> &n,vector<vector<int>> &ans,int arr[]){
    //         if(ds.size() == n.size()){
    //             ans.push_back(ds);
    //             return;
    //         }

    //         for(int i=0;i<n.size();i++){
    //             if(!arr[i]){
    //                 ds.push_back(n[i]);
    //                 arr[i]=1;
    //                 findPermute(ds,n,ans,arr);
    //                 arr[i]=0;
    //                 ds.pop_back();
    //             }
    //         }
    //     }

    // public:
    //     vector<vector<int>> permute(vector<int>& nums) {
    //         vector<vector<int>> ans;
    //         vector<int> ds;
    //         int freq[nums.size()];

    //         for(int i=0;i<nums.size();i++){
    //             freq[i]=0;
    //         }

    //         findPermute(ds,nums,ans,freq);

    //         return ans;
    //     }

private:
    void findPermute(int ind, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = ind; i < nums.size(); i++)
        {
            swap(nums[ind], nums[i]);
            findPermute(ind + 1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;

        findPermute(0, nums, ans);

        return ans;
    }
};
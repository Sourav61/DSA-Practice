// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // We can easily design brute force for this Quesiton but Time Complexity : O(N2) for brute force Approach

    // Thus to optimize our approach, we can hash maps and especially unordered map as we just need to store all elements in order

    // Unordered map is used here to map particular element with all of it's occureneces(indices) stored in a vector(list)

    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        // count variable used to track number of possible combinations staisfying given conditions in the question

        int count = 0;

        for(int i=0;i<n;i++){
            // We use find method to check next occurence of our current element in given vector 
            if(mp.find(nums[i]) != mp.end()){
                // Now we can simply iterate over indices of each element stored in vector mapped to that particular element in our unordered map
                for(auto x : mp[nums[i]])
                    // Herel, we check each pair of i and x(next occurences) for conditions given in the Question
                    if((i * x) % k == 0)
                        count++;
            }

            // We push all occurences after 1st occurence of any element into a particular vector stored for each element seperately
            mp[nums[i]].push_back(i);
        }
        
        return count;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {3,1,2,2,2,1,3};

    cout<<obj.countPairs(nums,2);

    return 0;
}
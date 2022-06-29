// https://leetcode.com/problems/group-anagrams/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto x:strs){
            string s = x;
            sort(s.begin(),s.end());
            mp[s].push_back(x);
        }
        vector<vector<string>> res;
        for(auto x : mp){
            res.push_back(x.second);
        }

        return res;
    }
};

int main(){

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> res = obj.groupAnagrams(strs);

    for(vectro<string> v : res){
        for(auto x : v){
            cout<<x<<" "; 
        }cout<<endl;
    }

    return 0;
}
// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
//         unordered_map<string, vector<string>> mp;
    
//         for(auto x : words){
//             if(x.length() == 1){
//                 cout<<x<<endl;
//                 mp[x] = {x};
//                 continue;
//             }
//             string s = x;
            
//             sort(s.begin(),s.end());
//             // cout<<s<<" "<<x<<endl;
//             mp[s].push_back(x);
//         }cout<<endl;
        
//         // for(auto x : mp){
//         //     for(auto v : x.second){
//         //         cout<<v<<" ";
//         //     }cout<<endl;
//         // }

//         vector<string> res;

//         for(auto x : mp){
//             res.insert(res.end(),x.second.begin(), x.second.begin()+1);
//         }
        
//         reverse(res.begin(),res.end());

//         return res;

        vector<string> ans;

        int n = words.size();

        string f = words[0];
        ans.push_back(f);
        sort(f.begin(),f.end());

        for(int i=1;i<n;i++){
            string s = words[i];
            sort(s.begin(),s.end());
            if(x == z)
                continue;
            else{
                ans.push_back(words[i]);
                f = s;           
            } 
        }

        return ans;
    }
};

int main(){

    vector<string> words = {"abba","baba","bbaa","cd","cd"};

    vector<string> res = obj.removeAnagrams(words);

    for(auto x:res){
        cout<<x<<" ";
    }cout<<endl;

    return 0;
}
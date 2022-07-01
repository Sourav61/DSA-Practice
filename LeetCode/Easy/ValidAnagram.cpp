// https://leetcode.com/problems/valid-anagram/submissions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() == t.length()){
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());

            return s==t;
        }
        
        return false;
    }
};

int main(){

    Solution obj;

    string s = "anagram";
    string t = "nagaram";

    cout<<obj.isAnagram(s,t)<<endl;

    return 0;
}
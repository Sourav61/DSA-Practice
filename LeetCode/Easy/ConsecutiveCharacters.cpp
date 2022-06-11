// https://leetcode.com/problems/consecutive-characters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int ans=0, count=1;
        char a;
        for(int i=0;i<s.length();i++){
            if(s[i] == s[i+1]){
                count++;
            }else{
                count=1;
            }
            ans = max(ans,count);
        }
        
        return ans;
    }
};

int main(){

    Solution obj;

    int ans = obj.maxPower("leetcode");

    cout<<ans<<endl;

    return 0;
}
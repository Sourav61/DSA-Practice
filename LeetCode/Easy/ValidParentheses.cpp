// https://leetcode.com/problems/valid-parentheses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool ans = true;

        for(int i=0;i<s.size();i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                st.push(s[i]);
            }else if(s[i] == ')'){
                if(!st.empty() and st.top() == '('){
                    st.pop();
                }else{
                    ans = false;
                    break;
                }
            }else if(s[i] == '}'){
                if(!st.empty() and st.top() == '{'){
                    st.pop();
                }else{
                    ans = false;
                    break;
                }
            }else if(s[i] == ']'){
                if(!st.empty() and st.top() == '['){
                    st.pop();
                }else{
                    ans = false;
                    break;
                }
            }
        }

        if(!st.empty()){
            return false;
        }

        return ans;
    }
};
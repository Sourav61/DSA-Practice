// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto s:tokens) {
            if(s.size()>1 || isdigit(s[0])){
                st.push(stoi(s));
            }else{
                auto b = st.top();
                st.pop();

                auto a = st.top();
                st.pop();

                switch(s[0]){
                    case '+':
                        st.push(a+b);
                        break;
                    case '-':
                        st.push(a-b);
                        break;
                    case '*':
                        st.push(a*b);
                        break;
                    case '/':
                        st.push(a/b);
                        break;
                    case '^':
                        st.push(pow(a,b));
                        break;
                }
            }
        }
        return st.top();
    }
};
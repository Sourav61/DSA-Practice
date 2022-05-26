// https://leetcode.com/problems/reverse-words-in-a-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int pre=-1;
        int n=s.length();
        string temp="";
        stack<string> st;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                if(temp.length()==0) continue;
                st.push(temp);
                temp="";
            }
            else
            {
                temp+=s[i];
            }
        }
        if(temp.length()!=0)
            st.push(temp);
        string res="";
        while(!st.empty())
        {
            string x=st.top();
            st.pop();
            res+=x;
            if(st.size()!=0)
                res+=" ";
        }
        return res;
    }
};
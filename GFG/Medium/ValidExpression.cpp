// https://practice.geeksforgeeks.org/problems/valid-expression1025/1/#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}// } Driver Code Ends


bool valid(string s)
{
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
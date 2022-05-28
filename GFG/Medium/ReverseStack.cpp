// https://practice.geeksforgeeks.org/problems/reverse-a-stack/1/#

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(vector<int>&v,stack<int>&st){
        if(st.size()==0){
            return;
        }
        int num=st.top();
        st.pop();
        v.push_back(num);
        solve(v,st);
    }
    vector<int> Reverse(stack<int> st){
        vector<int> v;
        solve(v,st);
        return v;
    }
};

// { Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans=ob.Reverse(St);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends
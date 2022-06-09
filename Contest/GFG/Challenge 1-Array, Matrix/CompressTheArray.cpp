// https://practice.geeksforgeeks.org/contest/challenge-1-array-matrix/problems/#

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function Template for C++


class Solution{
public:
    int compressArray(vector<int>& a, int n,int x){
        sort(a.begin(),a.end());
        
        int ans = 0;
        
        for(int i=0;i<n;){
            int index = i;
            
            while(index < n && a[i] == a[index]){
                index++;
            }

            int count = index-i;
            if(index == n or a[index] - a[i] > x){
                ans += count;
            }
            i = index;
        }

        return ans;
    }
};

// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int x;
        cin>>x;
        
        Solution obj;
        int ans = obj.compressArray(a,n,x);
        
        cout<<ans<<endl;
    }
}  // } Driver Code Ends
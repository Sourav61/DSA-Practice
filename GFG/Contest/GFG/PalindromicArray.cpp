// https://practice.geeksforgeeks.org/contest/challenge-1-array-matrix/problems/#

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


class Solution{
    public:
    int palindromicArray(vector<int>& a, int n,int k){
        int l = 0, r = n-1;
        while(l<r){
            if(a[l] == a[r]){
                l++;
                r--;
            }else if(a[l] == k){
                l++;
            }else if(a[r] == k){
                r--;
            }else{
                return false;
            }
        }
    
        return true;
    }
};

// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int k;
        cin>>k;
        Solution obj;
        bool ans = obj.palindromicArray(a,n,k);
        cout<<(ans == true ? "Yes": "No")<<endl;
    }
}  // } Driver Code Endss
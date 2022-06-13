// https://practice.geeksforgeeks.org/contest/challenge-2-searching-sorting/problems/#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


class Solution{
  public:
    vector<bool> matSearch(vector<vector<int>>& mat, int n, int m, int q, vector<vector<int>>& vec){
      for(int i=0;i<q;i++){
          for(int j=0;j<5;j++){
            cout<<vec[i][j]<<" ";
          }cout<<endl;
      }
  }
};

// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n,vector<int>(m));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        }
        
        int q;
        cin>>q;
        vector<vector<int>> vec(q,vector<int>(5));
        for(int i=0;i<q;i++){
            for(int j=0;j<5;j++){
                cin>>vec[i][j];
            }
        }
        
        Solution obj;
        vector<bool> ans = obj.matSearch(mat,n,m,q,vec);
        for(int i=0;i<ans.size();i++){
            cout<<(ans[i] == 1 ? "True": "False")<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends
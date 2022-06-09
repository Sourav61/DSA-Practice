// https://practice.geeksforgeeks.org/contest/challenge-1-array-matrix/problems/#

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


class Solution{
    public:
    vector<vector<int>> setMatrix(int n, int m, int q, vector<vector<int>> vec){
        vector<vector<int>> a(n, vector<int>(m,0));
        for(int i=0;i<q;i++){
            int x1 = vec[i][0];
            int y1 = vec[i][1];
            int x2 = vec[i][2];
            int y2 = vec[i][3];

            x1--;
            x2--;
            y1--;
            y2--;

            a[x1][y1]++;

            if(y2+1 < m){
                a[x1][y2+1]--;
            }

            if(x2+1 < n){
                a[x2+1][y1]--;
            }

            if(x2+1 < n and y2+1<m){
                a[x2+1][y2+1]++;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                a[i][j] += a[i][j-1];
            }
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j] += a[i-1][j];
            }
        }

        return a;
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int q;
        cin>>q;
        vector<vector<int>> vec(q,vector<int>(4));
        for(int i=0;i<q;i++){
            for(int j=0;j<4;j++){
                cin>>vec[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.setMatrix(n,m,q,vec);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}  // } Driver Code Ends
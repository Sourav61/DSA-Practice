// https://practice.geeksforgeeks.org/problems/points-in-straight-line/1

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
public:
    int maxPoints(int X[], int Y[], int N) {
        unordered_map<double,int> mp;
        int res = 1;
        
        for(int i=0;i<N-1;i++){
            for(int j=0;j<N;j++){
                if(i != j){
                    if(X[i] == X[j]){
                        mp[1000001]++;
                    }else{
                        double slope = double(Y[j] - Y[i]) / double(X[j] - X[i]);
                        mp[slope]++;
                    }
                }
            }
            
            for(auto &x : mp){
                // cout<<x.first<<" "<<x.second<<endl;
                res = max(res, x.second + 1);
            }
            // cout<<endl;
            mp.clear();
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x[n], y[n];
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        for(int i=0;i<n;i++){
            cin>>y[i];
        }
        Solution ob;
        cout << ob.maxPoints(x, y, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/queries-on-a-matrix0443/1?page=1&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=accuracy

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        vector<vector<int>> dp(n,vector<int>(n,0));
        int q = Queries.size();
        for(auto &x : Queries){
            int ra = x[0];
            int ca = x[1];
            int rb = x[2];
            int cb = x[3];
            
            for(int i=ra;i<=rb;i++){
                dp[i][ca] += 1;
                if(cb+1 < n)
                    dp[i][cb+1] -= 1;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                dp[i][j] += dp[i][j-1];
            }
        }
        return dp;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++) {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++) cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

int lcs(string &s, string &t){
    int n = s.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    
    for(int j=0;j<=n;j++){
        dp[0][j] = 0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[n][n];
}


int minDeletions(string s, int n) {
    string t = s;
    reverse(t.begin(),t.end());
    return n - lcs(s,t);
} 
// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1

//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int mod = 1000000007;
    
    /*You are required to complete below method */
    long long int f(int i,int j,string &s,vector<vector<int>> &dp){
        if(i > j){
            return dp[i][j] = 0;
        }
        
        if(i == j){
            return dp[i][j] = 1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s[i] == s[j]){
            return dp[i][j] = (1 + f(i+1, j,s, dp)%mod + f(i,j-1,s,dp)%mod+mod)%mod;
        }
        
        return dp[i][j] = (f(i+1,j,s,dp)%mod + f(i,j-1,s,dp)%mod - f(i+1,j-1,s,dp)%mod+mod)%mod;
    }
    
    long long int  countPS(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,n-1,s,dp)%mod;
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends
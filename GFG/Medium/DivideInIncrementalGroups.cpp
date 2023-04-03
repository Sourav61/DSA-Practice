// https://practice.geeksforgeeks.org/problems/c239059f6d110e6778cc2f2a1ab58ffd0a3d64ca/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int help(int n,int w,int cnt,vector<int> &a,vector<vector<vector<int>>> &dp)
    {
    	if(w == 0)
    	    return cnt == 0;
    	
    	if(n == a.size() || cnt == 0)
    	    return 0;
    	
    	if(dp[n][w][cnt]!=-1)
            return dp[n][w][cnt];
    	
    	int notake = help(n+1,w,cnt,a,dp);
    	
    	if(a[n]<=w)
    	{
    	    int take=help(n,w-a[n],cnt-1,a,dp);
    	    
    	    return dp[n][w][cnt] = (take + notake);
    	}
        
        return dp[n][w][cnt] = notake;
    }
    int countWaystoDivide(int N, int K) {
        // Code here
        vector<int> a;
        
        for(int i=1;i<=N;i++)
            a.push_back(i);
        vector<vector<vector<int>>> dp(a.size()+1,vector<vector<int>>(N+1,vector<int>(K+1,-1)));
        
        return help(0,N,K,a,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/sequence-fun5018/1

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
		int NthTerm(int n){
		    int mod = 1000000007;
		    long long int prev = 2 ,cur = 1;
		    for(int i=1;i<n;i++){
		        cur = (prev * (i+1))%mod + 1;
		        prev = cur;
		    }
		    
		    return prev;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/86e609332c9ef4f6b8aa79db11a6c0808c4a1bca/1

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        priority_queue<int,vector<int>,greater<int>> minH;
        int res = 0;
        for(auto &x : arr){
            minH.push(x);
        }
        
        while(minH.size() != 1){
            auto a = minH.top();
            minH.pop();
            auto b = minH.top();
            minH.pop();
            
            res += (a+b);
            
            minH.push(a+b);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends
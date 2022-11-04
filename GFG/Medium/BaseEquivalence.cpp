// https://practice.geeksforgeeks.org/problems/base-equivalence1022/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string baseEquiv(int n, int m){
        int low = 2,high = 32,mid;
        
        while(low <= high){
            mid = (low + high)/2;
            
            int cur = n, count = 0;
            
            while(cur != 0){
                count++;
                cur /= mid;
            }
            
            if(count == m){
                return "Yes";
            }else if(count < m){
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends
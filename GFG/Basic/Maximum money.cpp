// https://practice.geeksforgeeks.org/problems/maximum-money2855/1/?problemStatus=solved&difficulty[]=-1&page=1&query=problemStatussolveddifficulty[]-1page1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int maximizeMoney(int N , int K) {
        return (N-floor(N/2))*K;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;

        cin>>N>>K;

        Solution ob;
        cout << ob.maximizeMoney(N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends

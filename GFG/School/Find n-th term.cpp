// https://practice.geeksforgeeks.org/problems/find-n-th-term-of-series-1-3-6-10-15-215506/1/?problemStatus=solved&difficulty[]=-2&page=1&query=problemStatussolveddifficulty[]-2page1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findNthTerm(int N) {
        return N*(N+1)/2;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.findNthTerm(N) << endl;
    }
    return 0;
}  // } Driver Code Ends

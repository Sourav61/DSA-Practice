// https://practice.geeksforgeeks.org/problems/mind-game3637/1/?problemStatus=solved&difficulty[]=-1&page=1&query=problemStatussolveddifficulty[]-1page1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int mindGame(int K) {
        return (((2*3)+K)/2)-3;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int K;
        
        cin>>K;

        Solution ob;
        cout << ob.mindGame(K) << endl;
    }
    return 0;
}  // } Driver Code Ends

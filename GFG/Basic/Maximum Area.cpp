// https://practice.geeksforgeeks.org/problems/maximum-area2642/1/?problemStatus=solved&difficulty[]=-1&page=1&query=problemStatussolveddifficulty[]-1page1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int getHypotenuse(long long N) {
        return 2*sqrt(N);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;

        cin>>N;

        Solution ob;
        cout << ob.getHypotenuse(N) << endl;
    }
    return 0;
}  // } Driver Code Ends

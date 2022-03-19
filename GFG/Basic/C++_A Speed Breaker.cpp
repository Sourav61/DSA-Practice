// https://practice.geeksforgeeks.org/problems/c-a-speed-breaker5249/1/?problemStatus=solved&difficulty[]=-1&page=1&query=problemStatussolveddifficulty[]-1page1

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void speedBreaker(double a, int b){
        cout<<fixed<<setprecision(b)<<a<<endl;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        double a;
        cin >> a;
        int b;
        cin >> b;
        Solution ob;
        ob.speedBreaker(a,b);
    }
    return 0;
}
  // } Driver Code Ends

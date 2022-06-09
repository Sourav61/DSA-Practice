// https://practice.geeksforgeeks.org/contest/interview-series-53/problems/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        int n = s.length();
        int count = 0;
        
        for(int i=n-1;i>=0;i--){
            if(i%2 == 0){
                if(s.substr(0,i/2) == s.substr(i/2,i/2+1)){
                    s = s.substr(i/2);
                    count+=s.length()+1;
                    return count;
                }
            }else{
                if(s.substr(0,i/2+1) == s.substr((i/2)+1,(i/2)+1)){
                    s = s.substr(i/2+1);
                    count+=s.length()+1;
                    return count;
                }
            }
            
        }
        return n;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}
  // } Driver Code Endss
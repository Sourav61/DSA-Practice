// https://practice.geeksforgeeks.org/problems/fda70097eb2895ecfff269849b6a8aace441947c/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        int res = 1;
        int n = B.length();
        string temp = A;
        while(temp.length() < n){
            temp += A;
            res++;
        }
        
        if(temp.find(B) != string::npos){
            return res;
        }
        
        temp += A;
        
        if(temp.find(B) != string::npos){
            return res + 1;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Endss
// https://practice.geeksforgeeks.org/problems/13eb74f1c80bc67d526a69b8276f6cad1b8c3401/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int i = 0, j = 0;
        int n = S.length(), m = T.length();
        
        while(i < n && j < m){
            if(S[i] == T[j]){
                i++;
                j++;
                continue;
            }
            
            int temp = 0, k=0;
            while(j < m && isdigit(T[j])){
                temp = temp * 10 + (T[j] - '0');
                j++;
                k++;
            }
            
            i += temp;
            
            if(temp == 0){
                return 0;
            }
        }
        
        if(i == n && j == m){
            return 1;
        }
        
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/c-basic-data-types3128/1/?problemStatus=solved&difficulty[]=-1&page=1&query=problemStatussolveddifficulty[]-1page1

// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User functiom template for C++

class Solution {
  public:
    int BasicDataType(string S) {
        int l = S.length(), ans;
        if (l == 1) {
            //checking if S is integer of size 1
            if (isdigit(S[0]))
                ans = 4;
            else
                ans = 1;
        } else {
            int flag = 0;
            for (int i = 0; i < l; i++) {
                //checking whether S is integer or float/double
                if (S[i] == '.') {
                    flag = 1;
                    int j = l - i + 1;
                    //checking whether S is double
                    if (j > 7)
                        ans = 8;
                    else
                        ans = 4;
                }
            }
            if (!flag) ans = 4;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.BasicDataType(S) << endl;
    }
}  // } Driver Code Ends

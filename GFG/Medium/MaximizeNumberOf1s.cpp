// https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1/#

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        int zeroCnt = 0, ans = INT_MIN, i=0;
        
        for(int j=0;j<n;j++){
            if(arr[j] == 0){
                zeroCnt++;
            }

            while(zeroCnt > m){
                if(arr[i] == 0){
                    zeroCnt--;
                }
                i++;
            }

            ans = max(ans, j-i+1);
        }

        return ans;
    }  
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Endss
// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int dup = -1, missing = 1;
        
        int *res = new int[2]{-1};
        
        for(int i=0;i<n;i++){
            int cur = abs(arr[i])-1;
            
            if(arr[cur] < 0){
                res[0] = abs(cur+1);
            }
            else{
                arr[cur] *= -1;
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[i] > 0){
                res[1] = i+1;
                break;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
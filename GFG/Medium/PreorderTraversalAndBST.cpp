// https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1#

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int i = 0;
    void helper(int low, int high, int pre[],int n){
        if(i >= n || pre[i] > high || pre[i] < low){
            return;
        }

        int limit = pre[i++];
        helper(low, limit, pre, n);
        helper(limit, high, pre, n);
    }

    int canRepresentBST(int arr[], int n) {
        helper(INT_MIN, INT_MAX, arr,n);
        if(i >= n)
            return 1;

        return 0;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}  // } Driver Code Ends
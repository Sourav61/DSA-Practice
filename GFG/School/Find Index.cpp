// https://practice.geeksforgeeks.org/problems/second-largest3735/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&difficulty[]=-2&page=1&query=category[]ArraysproblemStatusunsolveddifficulty[]-2page1category[]Arrays#

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    int f,s;
	    f=s=INT_MIN;
	    for(int i=0;i<n;i++){
	        if(arr[i]>f){
	            s=f;
	            f=arr[i];
	        }
	        else if(s<arr[i] && arr[i]<f){
	            s=arr[i];
	        }
	    }
	    if(s>0){
	        return s;
	    }else{
	        return -1;
	    }
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends

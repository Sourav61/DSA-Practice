// https://practice.geeksforgeeks.org/problems/print-elements-of-array4910/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&difficulty[]=-2&page=1&query=category[]ArraysproblemStatusunsolveddifficulty[]-2page1category[]Arrays

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    //Just print the space seperated array elements
	void printArray(int arr[], int n) {
	    for(int i=0;i<n;i++){
	        cout<<arr[i]<<" ";
	    }
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.printArray(arr, n);
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends

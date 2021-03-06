// https://practice.geeksforgeeks.org/problems/print-the-left-element2009/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&difficulty[]=-2&page=1&query=category[]ArraysproblemStatusunsolveddifficulty[]-2page1category[]Arrays#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int leftElement(int a[], int n) {
        int count = 1;
        while (count < n)
        {
            for (int i = 0; i < n - count; i++)
            {
                if (a[i] > a[i + 1])
                {
                    int temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                }
            }
            count++;
        }
        if(n%2==0){
            // cout<<a[(n/2)-1]<<endl;
            return a[(n/2)-1];
        }else{
            // cout<<a[n/2]<<endl;
            return a[n/2];
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
        int a[n], i;
        for (i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.leftElement(a, n) << endl;
    }
}
  // } Driver Code Ends

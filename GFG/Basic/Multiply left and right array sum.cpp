// https://practice.geeksforgeeks.org/problems/multiply-left-and-right-array-sum1555/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&difficulty[]=-2&difficulty[]=-1&page=1&query=category[]ArraysproblemStatusunsolveddifficulty[]-2difficulty[]-1page1category[]Arrays#

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int multiply(int arr[], int n);


int main() {
	//code
	int t;
	cin>>t;
	while (t--)
	{
	    int n,sum1=0,sum2=0;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    
	    cout << multiply(a, n) << endl;
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

int multiply(int arr[], int n)
{
    int a=0,b=0;
    if(n%2==0){
        for(int i=0;i<n;i++){
            if(i<n/2){
                a+=arr[i];
            }else{
                b+=arr[i];
            }
        }
    }else{
        for(int i=0;i<n;i++){
            if(i<n/2){
                a+=arr[i];
            }else{
                b+=arr[i];
            }
        }
    }
    
    return a*b;
}

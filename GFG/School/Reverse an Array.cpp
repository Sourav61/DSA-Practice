// https://practice.geeksforgeeks.org/problems/reverse-an-array/0/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&difficulty[]=-2&page=1&query=category[]ArraysproblemStatusunsolveddifficulty[]-2page1category[]Arrays#

#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    int e=n-1;
	    
	    for(int i=0;i<n;i++){
	        if(i<n/2){
    	        int temp=a[i];
    	        a[i]=a[e];
    	        a[e]=temp;
    	        e--;
	        }
	        cout<<a[i]<<" ";
	    }cout<<endl;
	   
	   
	}
	return 0;
}

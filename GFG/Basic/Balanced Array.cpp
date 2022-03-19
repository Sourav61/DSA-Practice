// https://practice.geeksforgeeks.org/problems/balanced-array07200720/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&difficulty[]=-2&difficulty[]=-1&page=1&query=category[]ArraysproblemStatusunsolveddifficulty[]-2difficulty[]-1page1category[]Arrays#

// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int minValueToBalance(int a[], int n)
    {
        int x=0,b=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                x+=a[i];
            }else{
                b+=a[i];
            }
        }
        
        if(x>b){
            return x-b;
        }else{
            return b-x;
        }
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.minValueToBalance(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends

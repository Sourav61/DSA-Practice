// https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&difficulty[]=-2&page=1&query=category[]ArraysproblemStatusunsolveddifficulty[]-2page1category[]Arrays#

// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
}// } Driver Code Ends


/*Complete the function below*/
int PalinArray(int a[], int n)
{  
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        int rem=0;
        while(x!=0)
        {
            rem=(rem*10)+(x%10);
            x=x/10;
        }
        if(a[i]!=rem)
            return 0;
    }
    return 1;
}

// https://practice.geeksforgeeks.org/problems/minimum-number-to-form-the-sum-even0326/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&difficulty[]=-2&difficulty[]=-1&page=1&query=category[]ArraysproblemStatusunsolveddifficulty[]-2difficulty[]-1page1category[]Arrays

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	int minNum(long long int arr[],int n)
	{
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    if(sum%2==0){
	        return 2;
	    }else{
	        return 1;
	    }
	}

		 

};
	

// { Driver Code Starts.


int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	 int n;
        cin>>n;
        
        long long a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        
        
      
        Solution ob;
		cout << ob.minNum(a, n);
        
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends

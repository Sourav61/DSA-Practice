// https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int a[], int n, int target)
    {
        bool found = false;
        sort(a,a+n);

        for(int i=0;i<n;i++){
            int lo = i + 1, hi = n - 1;
            while(lo<hi){
                int current = a[i] + a[lo] + a[hi];
                if(current == target){
                    found = true;
                }

                if(current<target){
                    lo++;
                }else{
                    hi--;
                }
            }
        }

        return found;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends
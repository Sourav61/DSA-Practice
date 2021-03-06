// https://practice.geeksforgeeks.org/problems/product-of-maximum-in-first-array-and-minimum-in-second3943/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&difficulty[]=-2&difficulty[]=-1&page=1&query=category[]ArraysproblemStatusunsolveddifficulty[]-2difficulty[]-1page1category[]Arrays#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        long long find_multiplication(int a[], int b[], int n, int m)
    {
        int mina,maxa,minb,maxb;
        maxa=maxb=INT_MIN;
        mina=minb=INT_MAX;
        if (n == 1)
        {
            maxa = mina= a[0];   
        }
        if(n==2){
            if (a[0] > a[1])
            {
                maxa = a[0];
                mina=a[1];
            }
            else
            {
                maxa = a[1];
                mina=a[0];
            }
        }
    
        for(int i = 0; i < n; i++)
        {
            if (a[i] > maxa)    
                maxa = a[i];
                
        }
    
        
        
        if (m == 1)
        {
            // max = a[0];
            minb = b[0];
            maxb = b[0];
        }
        else if(m==2){
            if (b[0] > b[1])
            {
                // max = a[0];
                minb = b[1];
                maxb = b[2];
            }
            else
            {
                maxb = a[1];
                minb = b[0];
            }
            
        }
        else{
            for(int i = 0; i < m; i++)
            {
                if (b[i] <minb)    
                    minb = b[i];
        
                
            }
        }
        
        return maxa*minb;
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
        for(int i=0;i<n;i++)    cin>>a[i];
        
        int m;
        cin>>m;
        int b[m];
        for(int i=0;i<m;i++)    cin>>b[i];
        
        
        Solution ob;
        cout<<ob.find_multiplication(a, b, n, m)<<endl;

    }
    return 0;
}  // } Driver Code Ends

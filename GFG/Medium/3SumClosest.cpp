// https://practice.geeksforgeeks.org/problems/3-sum-closest/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int a[], int n, int target)
    {
        if(n < 3){
            return INT_MAX;
        }
        sort(a,a+n);
        
        int ans = a[0] + a[1] + a[2];

        for(int i=0;i<n;i++){
            int l = i+1, r=n-1;

            while(l<r){
                int sum = a[i] + a[l] + a[r];

                if(abs(sum-target) < abs(ans-target)){
                    ans = sum;
                }

                if(sum < target){
                    l++;
                }else{
                    r--;
                }
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}  // } Driver Code Endss
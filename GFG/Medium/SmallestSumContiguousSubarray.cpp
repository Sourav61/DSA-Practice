// https://practice.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1?page=1&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=accuracy

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int smallestSumSubarray(vector<int> &a)
    {
        // ===========================     Reverse Kadane's Algo    ====================================

        // int n=a.size();
        // for(int i=0;i<n;i++) a[i]*=-1;

        // int maxSum=a[0];
        // int curr_sum=0;

        // for(int i=0;i<n;i++){
        //     curr_sum+= a[i];
        //     maxSum= max(maxSum, curr_sum);

        //     if(curr_sum<0) {
        //         curr_sum= 0;
        //         maxSum= max(maxSum, a[i]);
        //     }
        // }
        // return -maxSum;

        // ===========================     Tabulation Algo    ====================================

        int n=a.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            dp[i] = a[i];
        }

        for(int i=1;i<n;i++){
            dp[i] = min(dp[i], dp[i-1] + a[i]);
        }

        int mini = INT_MAX;

        for(int i=0;i<n;i++){
            mini = min(mini,dp[i]);
        }

        return mini;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        int ans = ob.smallestSumSubarray(a);

        cout << ans << endl;
    }
}
// } Driver Code Ends
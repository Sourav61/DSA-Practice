// https://practice.geeksforgeeks.org/problems/array-removals/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int removals(vector<int> &arr, int k)
    {
        // sort(arr.begin(),arr.end());

        // int res = -1;
        // int n = arr.size();
        // for(int i=0;i<n;i++){
        //     int maxi;
        //     if(arr[i] + k > arr[n-1]){
        //         maxi = arr[n-1];
        //     }else{
        //         maxi = arr[i] + k;
        //     }
        //     int cnt = 0;

        //     int j=i;

        //     while(arr[j] <= maxi && j<n){
        //         cnt++;
        //         j++;
        //     }

        //     res = max(res, cnt);
        // }

        // return n-res;

        sort(arr.begin(), arr.end());

        int l = 0, r = 0, res = 0;
        int n = arr.size();

        while (r < n)
        {
            if (arr[r] - arr[l] <= k)
            {
                r++;
                res = max(res, r - l);
            }
            else
            {
                l++;
            }
        }

        return n - res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        int ans = ob.removals(arr, k);

        cout << ans << endl;
    }
}

// } Driver Code Ends
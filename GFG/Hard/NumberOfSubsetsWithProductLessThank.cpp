// https://practice.geeksforgeeks.org/problems/number-of-subsets-with-product-less-than-k/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void solve(int arr[], int N, int K, int i, int &ans, int pd)
    {
        if (i >= N)
            return;
        if (pd * arr[i] <= K)
        {
            ans++;
        }
        if (pd > K)
            return;
        solve(arr, N, K, i + 1, ans, pd * arr[i]);
        solve(arr, N, K, i + 1, ans, pd);
    }
    int numOfSubsets(int arr[], int N, int K)
    {
        int ans = 0;
        solve(arr, N, K, 0, ans, 1);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> K;

        Solution ob;
        cout << ob.numOfSubsets(arr, N, K) << endl;
    }
    return 0;
}
// } Driver Code Ends

// void findSubsets(int ind, int arr[], int n, int k, vector<int> &ds, int &count, int &mult)
// {
//     for (int i = ind; i <= n; i++)
//     {
//         if (i == n)
//         {
//             // cout<<mult<<" "<<arr[i]<<endl;
//             if (mult <= k && ds.size() > 0)
//             {
//                 count++;
//             }
//         }

//         ds.push_back(arr[i]);
//         if (i < n)
//         {
//             mult *= arr[i];
//         }
//         // cout<<mult<<" 1 "<<arr[i]<<endl;
//         findSubsets(i + 1, arr, n, k, ds, count, mult);
//         if (i < n)
//         {
//             mult /= arr[i];
//         }
//         // cout<<mult<<" 2 "<<arr[i]<<endl;
//         ds.pop_back();
//     }
// }

// int numOfSubsets(int arr[], int N, int K)
// {
//     int count = 0;
//     int mult = 1;
//     vector<int> ds;
//     findSubsets(0, arr, N, K, ds, count, mult);
//     return count;
// }
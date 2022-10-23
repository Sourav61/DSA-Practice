// https://practice.geeksforgeeks.org/problems/next-permutation5226/1?page=1&status[]=bookmarked&sortBy=submissions

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        vector<int> res;
        int l, k;
        for (k = N - 2; k >= 0; k--)
        {
            if (arr[k] < arr[k + 1])
            {
                break;
            }
        }
        if (k < 0)
        {
            for (int i = N - 1; i >= 0; i--)
            {
                res.push_back(arr[i]);
            }
        }
        else
        {
            for (l = N - 1; l > k; l--)
            {
                if (arr[l] > arr[k])
                {
                    break;
                }
            }
            swap(arr[k], arr[l]);
            for (int i = 0; i <= k; i++)
            {
                res.push_back(arr[i]);
            }

            for (int i = N - 1; i > k; i--)
            {
                res.push_back(arr[i]);
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for (int u : ans)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1/?page=1&status[]=unsolved&category[]=Arrays&sortBy=submissions#

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        const int N = 1e6 + 2;
        bool check[N];

        int mx = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            check[i] = 0;
            mx = max(arr[i], mx);
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                check[arr[i]] = 1;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (check[i] == false)
            {
                return i;
            }
        }

        return mx + 1;
    }
};

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main()
{

    // taking testcases
    int t;
    cin >> t;
    while (t--)
    {

        // input number n
        int n;
        cin >> n;
        int arr[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        // calling missingNumber()
        cout << ob.missingNumber(arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends
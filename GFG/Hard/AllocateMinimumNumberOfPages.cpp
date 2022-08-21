// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    // Function to find minimum number of pages.
    bool isPosible(int arr[], int n, int m, int mid)
    {
        int pageSum = 0;
        int studentCount = 1;

        for (int i = 0; i < n; i++)
        {
            if (pageSum + arr[i] <= mid)
                pageSum = pageSum + arr[i];

            else
            {
                studentCount++;
                if (studentCount > m || arr[i] > mid)
                    return 0;

                pageSum = arr[i];
            }
        }

        return 1;
    }

    int findPages(int A[], int N, int M)
    {
        int sum = 0;

        int result = -1;

        for (int i = 0; i < N; i++)
            sum += A[i];

        int s = 0;
        int e = sum;

        int mid = s + (e - s) / 2;

        while (s <= e)
        {
            if (isPosible(A, N, M, mid))
            {
                result = mid;

                e = mid - 1;
            }

            else
                s = mid + 1;

            mid = s + (e - s) / 2;
        }

        return result;
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
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
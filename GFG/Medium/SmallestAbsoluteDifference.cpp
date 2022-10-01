// https://practice.geeksforgeeks.org/problems/smallest-absolute-difference4320/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
int kthDiff(int a[], int n, int k);

// Driver code
int main()
{
    int t, i;
    int k;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> k;

        cout << kthDiff(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends

bool isPossible(int a[], int diff, int k, int n)
{
    int pairs = 0;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        while (j < n && nums[i] - nums[j] <= diff)
            j++;

        pairs += (j - i - 1);
    }

    return pairs >= k;
}

int kthDiff(int a[], int n, int k)
{
    int low = 0;
    int high = 1e5;

    sort(a, a + n);

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (isPossible(a, mid, k, n))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}
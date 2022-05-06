// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

    long long merge(long long arr[], long long l, long long mid, long long r)
    {
        long long inv = 0;
        long long n1 = mid - l + 1;
        long long n2 = r - mid;

        long long a[n1];
        long long b[n2];

        for (long long i = 0; i < n1; i++)
        {
            a[i] = arr[l + i];
        }

        for (long long i = 0; i < n2; i++)
        {
            b[i] = arr[mid + i + 1];
        }

        long long i = 0, j = 0, k = l;

        while (i < n1 and j < n2)
        {
            if (a[i] <= b[j])
            {
                arr[k] = a[i];
                k++;
                i++;
            }
            else
            {
                arr[k] = b[j];
                // a[i] > b[j] and i<j
                // Here if a[i] > b[j], then all elements after a[i] till i<n1 will always be greater than b[j]
                // Thus total number of inversions will be n-i;
                inv += n1 - i;
                k++;
                j++;
            }
        }

        while (i < n1)
        {
            arr[k] = a[i];
            k++;
            i++;
        }

        while (j < n2)
        {
            arr[k] = b[j];
            k++;
            j++;
        }

        return inv;
    }

    long long mergeSort(long long a[], long long l, long long r)
    {
        long long inv = 0;
        if (l < r)
        {
            long long mid = (l + r) / 2;
            inv += mergeSort(a, l, mid);
            inv += mergeSort(a, mid + 1, r);

            inv += merge(a, l, mid, r);
        }

        // cout<<inv<<endl;

        return inv;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        long long int ans = mergeSort(arr, 0, N - 1);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}
// } Driver Code Endss
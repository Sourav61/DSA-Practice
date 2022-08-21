// https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int search(int arr[], int left, int right, int key)
    {
        if (left > right)
            return -1;

        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[left] <= arr[mid])
        {
            if (key >= arr[left] && key <= arr[mid])
                return search(arr, left, mid - 1, key);
            return search(arr, mid + 1, right, key);
        }

        if (key >= arr[mid] && key <= arr[right])
            return search(arr, mid + 1, right, key);
        return search(arr, left, mid - 1, key);
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
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
    return 0;
}
// } Driver Code Ends
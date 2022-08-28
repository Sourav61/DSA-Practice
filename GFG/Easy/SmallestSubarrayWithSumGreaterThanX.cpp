// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int sum = 0, minLength = n + 1, start = 0, end = 0;

        while (end < n)
        {
            while (sum <= x && end < n)
            {
                sum += arr[end++];
            }

            while (sum > x && start < n)
            {
                if (end - start < minLength)
                    minLength = end - start;

                sum -= arr[start++];
            }
        }

        return minLength;
    }
};

//{ Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.smallestSubWithSum(a, n, x) << endl;
    }
    return 0;
}
// } Driver Code Ends
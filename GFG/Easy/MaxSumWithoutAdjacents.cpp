// https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(int *arr, int n)
    {
        int prev2 = 0;
        int prev = arr[0];

        for (int i = 1; i < n; i++)
        {
            int take = arr[i];
            if (i > 1)
            {
                take += prev2;
            }

            int ntake = 0 + prev;

            int curi = max(take, ntake);

            prev2 = prev;
            prev = curi;
        }

        return prev;
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
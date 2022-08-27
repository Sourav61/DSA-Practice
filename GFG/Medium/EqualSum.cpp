// https://practice.geeksforgeeks.org/problems/equal-sum0810/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string equilibrium(int *arr, int n)
    {
        int sum = 0, total = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            if ((i == 0 || i == n - 1) && sum - arr[i] == 0)
            {
                return true;
            }

            if (total == sum - total - arr[i])
            {
                return true;
            }

            total += arr[i];
        }

        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.equilibrium(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
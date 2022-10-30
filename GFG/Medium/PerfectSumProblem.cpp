// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int f(int idx, int target, int arr[], vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (target == 0 && arr[0] == target)
                return 2;
            else if (arr[0] == target || target == 0)
                return 1;
            else
                return 0;
        }

        if (dp[idx][target] != -1)
            return dp[idx][target];

        int notTake = f(idx - 1, target, arr, dp);
        int take = 0;

        if (arr[idx] <= target)
            take = f(idx - 1, target - arr[idx], arr, dp);

        return dp[idx][target] = (notTake + take) % 1000000007;
    }

    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(n - 1, sum, arr, dp);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";
    }
    return 0;
}

// } Driver Code Ends
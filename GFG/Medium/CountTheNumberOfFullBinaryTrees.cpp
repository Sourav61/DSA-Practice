// https://practice.geeksforgeeks.org/problems/count-the-number-of-full-binary-trees2525/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int numoffbt(long long int arr[], int n)
    {
        long long int mini = INT_MAX;
        long long int maxi = 1;

        for (int i = 0; i < n; i++)
        {
            mini = min(arr[i], mini);
            maxi = max(arr[i], maxi);
        }

        vector<long long int> dp(maxi + 1);

        for (int i = 0; i < n; i++)
        {
            dp[arr[i]] = 1;
        }

        long long int ans = 0;

        for (int i = mini; i <= maxi; i++)
        {
            if (dp[i] != 0)
            {
                for (int j = i + i; j <= maxi && (j / i) <= i; j += i)
                {
                    if (dp[j] != 0)
                    {
                        dp[j] += (dp[i] * dp[j / i]);
                        if (i != j / i)
                        {
                            dp[j] += dp[i] * dp[j / i];
                        }
                    }
                }

                ans = (ans + dp[i]) % 1000000007;
            }
        }

        return ans % 1000000007;
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
        int n;
        cin >> n;
        long long int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.numoffbt(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
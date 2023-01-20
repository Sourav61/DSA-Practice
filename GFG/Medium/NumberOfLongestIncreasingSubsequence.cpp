// https://practice.geeksforgeeks.org/problems/number-of-longest-increasing-subsequence/1?page=1&sortBy=newest&query=page1sortBynewest

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int NumberofLIS(int n, vector<int> &arr)
    {
        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = 1;

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if (arr[prev] < arr[i] && 1 + dp[prev] == dp[i])
                {
                    cnt[i] += cnt[prev];
                }
            }
            maxi = max(dp[i], maxi);
        }

        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxi)
            {
                res += cnt[i];
            }
        }

        return res;
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
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            long long x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.NumberofLIS(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
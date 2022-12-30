// Printing Longest Increasing Subsequence

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
    {
        int maxi = 1, lastIdx = 0;
        vector<int> dp(n, 1), hash(n, 0);

        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev <= i; prev++)
            {
                if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
                if (dp[i] > maxi)
                {
                    maxi = dp[i];
                    lastIdx = i;
                }
            }
        }

        vector<int> res;
        res.push_back(arr[lastIdx]);

        while (hash[lastIdx] != lastIdx)
        {
            lastIdx = hash[lastIdx];
            res.push_back(arr[lastIdx]);
        }

        reverse(res.begin(), res.end());

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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
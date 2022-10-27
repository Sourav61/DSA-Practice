// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        if (sum % 2 != 0)
            return false;

        vector<vector<int>> dp(N, vector<int>(sum / 2 + 1, 0));

        for (int i = 0; i < N; i++)
        {
            dp[i][0] = true;
        }

        if (arr[0] <= sum / 2)
            dp[0][arr[0]] = true;

        for (int ind = 1; ind < N; ind++)
        {
            for (int tar = 1; tar <= sum / 2; tar++)
            {
                bool notTake = dp[ind - 1][tar];
                bool take = false;
                if (arr[ind] <= tar)
                {
                    take = dp[ind - 1][tar - arr[ind]];
                }

                dp[ind][tar] = take | notTake;
            }
        }

        return dp[N - 1][sum / 2];
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
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/coin-change2448/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int f(int ind, int nums[], int x, vector<vector<long long int>> &dp)
    {
        if (ind == 0)
        {
            if (x % nums[0] == 0)
            {
                return 1;
            }
            return 0;
        }

        if (dp[ind][x] != -1)
        {
            return dp[ind][x];
        }

        long long int notTake = f(ind - 1, nums, x, dp);
        long long int take = 0;
        if (nums[ind] <= x)
        {
            take = f(ind, nums, x - nums[ind], dp);
        }

        return dp[ind][x] = take + notTake;
    }

    long long int count(int coins[], int N, int sum)
    {
        vector<vector<long long int>> dp(N, vector<long long int>(sum + 1, -1));
        return f(N - 1, coins, sum, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++)
            cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}

// } Driver Code Ends
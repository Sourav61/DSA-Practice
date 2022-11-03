// https://practice.geeksforgeeks.org/problems/target-sum-1626326450/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution
{
public:
    int findWays(vector<int> &num, int tar)
    {
        int n = num.size();

        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

        if (num[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (num[0] != 0 && num[0] <= tar)
        {
            dp[0][num[0]] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int sum = 0; sum <= tar; sum++)
            {
                int notTake = dp[i - 1][sum];
                int take = 0;
                if (num[i] <= sum)
                {
                    take = dp[i - 1][sum - num[i]];
                }

                dp[i][sum] = (notTake + take);
            }
        }

        return dp[n - 1][tar];
    }

    int countPartitions(int n, int d, vector<int> &arr)
    {
        int sum = 0;
        for (auto &x : arr)
        {
            sum += x;
        }

        if (sum - d < 0 || (sum - d) % 2)
            return false;

        return findWays(arr, (sum - d) / 2);
    }

    int findTargetSumWays(vector<int> &A, int target)
    {
        int n = A.size();
        return countPartitions(n, target, A);
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
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(arr, target);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
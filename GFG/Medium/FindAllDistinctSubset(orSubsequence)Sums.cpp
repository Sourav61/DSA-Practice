// https://practice.geeksforgeeks.org/problems/find-all-distinct-subset-or-subsequence-sums4424/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> DistinctSum(vector<int> nums)
    {
        int n = nums.size();
        int sum = 0;
        for (auto &x : nums)
        {
            sum += x;
        }
        vector<int> res;
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = true;
                }
                else if (i == 0)
                {
                    dp[i][j] = false;
                }
                else if (j >= nums[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        for (int i = 0; i <= sum; i++)
        {
            if (dp[n][i])
            {
                res.push_back(i);
            }
        }

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        vector<int> ans = obj.DistinctSum(nums);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m2546/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool help(int n, int w, int m, vector<int> &wt, vector<vector<int>> &dp)
    {
        if (w > 0 && w % m == 0)
            return true;

        if (n == 0 || w <= 0)
            return false;

        if (dp[n][w] != -1)
            return dp[n][w];
        else
        {
            if (wt[n - 1] <= w)
            {
                bool x = help(n - 1, w - wt[n - 1], m, wt, dp);
                bool y = help(n - 1, w, m, wt, dp);
                return dp[n][w] = x || y;
            }
            else
            {
                return dp[n][w] = help(n - 1, w, m, wt, dp);
            }
        }
    }

    int DivisibleByM(vector<int> nums, int m)
    {
        // Code here
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        return help(n, sum, m, nums, dp);
    }

    // 		int DivisibleByM(vector<int>arr, int m){
    // 		    // Code here
    // 		    int n = arr.size();

    //             int sum = 0;
    //             for(auto &x : arr){
    //                 sum += x;
    //             }

    //             vector<bool> cur(sum+1,0), prev(sum+1,0);
    //             prev[0] = cur[0] = true;
    //             prev[arr[0]] = true;

    //             for(int i=1;i<n;i++){
    //                 for(int target=1;target<=sum;target++){
    //                     bool notTake = prev[target];
    //                     bool take = false;
    //                     if(arr[i] <= target)
    //                         take = prev[target-arr[i]];

    //                     cur[target] = take | notTake;
    //                 }
    //                 for(int target = 1; target<=sum;target++){
    //                     if(target % m == 0 && cur[target]){
    //                         return 1;
    //                     }
    //                 }
    //                 prev = cur;
    //             }

    //             return 0;
    // 		}
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.DivisibleByM(nums, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
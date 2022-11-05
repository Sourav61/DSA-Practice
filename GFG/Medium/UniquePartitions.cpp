// https://practice.geeksforgeeks.org/problems/unique-partitions1041/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<vector<int>> res;
    void solve(vector<int> &nums, int target, int n, vector<int> &ans)
    {
        if (target == 0)
        {
            res.push_back(ans);
            return;
        }
        if (n <= 0)
            return;

        if (nums[n - 1] <= target)
        {
            ans.push_back(nums[n - 1]);
            solve(nums, target - nums[n - 1], n, ans);
            ans.pop_back();
        }

        solve(nums, target, n - 1, ans);
    }

    vector<vector<int>> UniquePartitions(int n)
    {
        vector<int> ans;
        vector<int> nums;
        res.clear();
        for (int i = 1; i <= n; i++)
        {
            nums.push_back(i);
        }
        solve(nums, n, n, ans);

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
        Solution ob;
        vector<vector<int>> ans = ob.UniquePartitions(n);
        for (auto i : ans)
            for (auto j : i)
                cout << j << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
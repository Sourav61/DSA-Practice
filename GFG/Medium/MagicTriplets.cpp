// https://practice.geeksforgeeks.org/problems/magic-triplets4003/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> res;
    int helper(int idx, queue<int> &q, vector<int> &nums, int n, int last)
    {
        if (idx == n)
        {
            return 0;
        }
        if (q.size() == 3)
        {
            res.clear();
            while (!q.empty())
            {
                cout << q.front() << " ";
                res.push_back(q.front());
                q.pop();
            }
            cout << nums[idx] << endl;

            q.push(res[0]);
            q.push(res[1]);
            q.push(res[2]);

            q.pop();
            return 1;
        }

        int notTake = helper(idx + 1, q, nums, n, last);
        int take = 0;

        if (nums[idx] < last)
        {
            q.push(nums[idx]);
            // cout<<nums[idx]<<" "<<last<<" "<<q.size()<<endl;
            last = nums[idx];
            take = helper(idx + 1, q, nums, n, last);
            last = nums[idx];
        }

        return take + notTake;
    }

    int countTriplets(vector<int> nums)
    {
        // int n = nums.size();
        // queue<int> q;

        // return helper(0, q, nums, n, 1000001);

        int n = nums.size();
        int ans = 0;

        for (int j = 1; j < n - 1; j++)
        {
            int smaller = 0;
            for (int i = j - 1; i >= 0; i--)
            {
                if (nums[i] < nums[j])
                    smaller++;
            }

            int larger = 0;

            for (int i = j + 1; i < n; i++)
            {
                if (nums[i] > nums[j])
                    larger++;
            }
            ans += smaller * larger;
        }

        return ans;
    }
};
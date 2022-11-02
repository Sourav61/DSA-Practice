// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

#include <bits/stdc++.h>

int f(int ind, vector<int> &wt, vector<int> &val, int W, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[0] <= W)
        {
            return val[0];
        }
        return 0;
    }

    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }

    int notTake = 0 + f(ind - 1, wt, val, W, dp);
    int take = INT_MIN;
    if (wt[ind] <= W)
    {
        take = val[ind] + f(ind - 1, wt, val, W - wt[ind], dp);
    }

    return dp[ind][W] = max(take, notTake);
}

int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);

    for (int W = wt[0]; W <= maxWeight; W++)
    {
        prev[W] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = maxWeight; W >= 0; W--)
        {
            int notTake = prev[W];
            int take = INT_MIN;
            if (wt[ind] <= W)
            {
                take = val[ind] + prev[W - wt[ind]];
            }

            prev[W] = max(take, notTake);
        }
    }

    return prev[maxWeight];
}
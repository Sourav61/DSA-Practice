// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

#include <bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;

        if (i > 1)
            ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);

        dp[i] = min(fs, ss);
    }
    return dp[n - 1];
}
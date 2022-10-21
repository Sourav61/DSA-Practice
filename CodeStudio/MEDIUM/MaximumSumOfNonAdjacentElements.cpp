// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0

#include <bits/stdc++.h>

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += prev2;
        int npick = 0 + prev;
        int curi = max(pick, npick);

        prev2 = prev;
        prev = curi;
    }
    return prev;
}
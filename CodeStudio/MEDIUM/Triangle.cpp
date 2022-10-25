// https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0s

#include <bits/stdc++.h>

int minimumPathSum(vector<vector<int>> &triangle, int n)
{

    vector<int> prev(n, 100000);
    for (int row = 0; row < n; row++)
    {
        vector<int> cur(n, 100000);
        for (int j = 0; j <= row; j++)
        {
            if (j == 0 && row == 0)
            {
                cur[j] = triangle[row][j];
                continue;
            }

            int up = 0, left = 0;

            up = prev[j];
            if (j == 0)
            {
                left = INT_MAX;
            }
            else
            {
                left = prev[j - 1];
            }

            cur[j] = min(up, left) + triangle[row][j];
        }
        prev = cur;
    }

    int mini = INT_MAX;

    for (int j = 0; j < n; j++)
    {
        mini = min(mini, prev[j]);
    }

    return mini;
}
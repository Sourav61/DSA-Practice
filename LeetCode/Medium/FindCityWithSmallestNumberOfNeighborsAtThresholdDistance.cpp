// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 0;
        }

        for (auto x : edges)
        {
            int src = x[0];
            int dest = x[1];
            int cost = x[2];

            dp[src][dest] = cost;
            dp[dest][src] = cost;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dp[i][k] + dp[k][j] < dp[i][j])
                    {
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }

        int mini = INT_MAX, res = -1;

        for (int i = n - 1; i >= 0; i--)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                if (dp[i][j] <= distanceThreshold)
                    cnt++;
            }

            if (cnt < mini)
            {
                mini = cnt;
                res = i;
            }
        }
        return res;
    }
};

int main()
{

    Solution obj;

    int n = 4;

    vector<vector<int>> edges{{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;

    cout << obj.findTheCity(n, edges, distanceThreshold);

    return 0;
}
// https://leetcode.com/problems/total-cost-to-hire-k-workers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        priority_queue<int, vector<int>, greater<int>> minHL, minHR;

        int n = costs.size();
        vector<int> vis(n, 0);

        long long totalCost = 0;

        int l = candidates, r = n - 1 - candidates;

        for (int i = 0; i < candidates && i < n; i++)
        {
            minHL.push(costs[i]);
            vis[i] = 1;
        }

        for (int i = n - candidates; i < n; i++)
        {
            if (vis[i] == 1)
                continue;
            minHR.push(costs[i]);
            vis[i] = 1;
        }

        int ans = 0;

        while (k--)
        {
            if (minHL.size() != 0 && (minHR.size() == 0 || minHL.top() <= minHR.top()))
            {
                totalCost += minHL.top();
                minHL.pop();

                if (l <= n - 1 && !vis[l])
                {
                    vis[l] = 1;
                    minHL.push(costs[l++]);
                }
            }
            else
            {
                totalCost += minHR.top();
                minHR.pop();
                ans++;
                if (r >= 0 && !vis[r])
                {
                    vis[r] = 1;
                    minHR.push(costs[r--]);
                }
            }
        }

        return totalCost;
    }
};

int main()
{

    Solution obj;

    vector<int> costs = {17, 12, 10, 2, 7, 2, 11, 20, 8};
    int k = 3;
    int candidates = 4;

    cout << obj.totalCost(costs, k, candidates);

    return 0;
}
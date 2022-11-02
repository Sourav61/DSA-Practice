// https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int x)
    {
        int n = coins.size();
        vector<int> prev(x + 1, 0), cur(x + 1, 0);

        for (int T = 0; T <= x; T++)
        {
            if (T % coins[0] == 0)
            {
                prev[T] = T / coins[0];
            }
            else
            {
                prev[T] = 1e9;
            }
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int T = 0; T <= x; T++)
            {
                int notTake = prev[T];
                int take = INT_MAX;
                if (coins[ind] <= T)
                {
                    take = 1 + cur[T - coins[ind]];
                }

                cur[T] = min(take, notTake);
            }
            prev = cur;
        }

        int res = prev[x];

        if (res >= 1e9)
        {
            return -1;
        }
        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 2, 5};
    int x = 3;

    cout << obj.coinChange(nums, x);

    return 0;
}
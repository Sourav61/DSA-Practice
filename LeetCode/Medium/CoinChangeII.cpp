// https://leetcode.com/problems/coin-change-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int f(int ind, vector<int> &coins, int x, vector<vector<long long int>> &dp)
    {
        if (ind == 0)
        {
            if (x % coins[0] == 0)
            {
                return 1;
            }
            return 0;
        }

        if (dp[ind][x] != -1)
        {
            return dp[ind][x];
        }

        long long int notTake = f(ind - 1, coins, x, dp);
        long long int take = 0;
        if (coins[ind] <= x)
        {
            take = f(ind, coins, x - coins[ind], dp);
        }

        return dp[ind][x] = take + notTake;
    }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<long long int>> dp(n, vector<long long int>(amount + 1, -1));
        return f(n - 1, coins, amount, dp);
    }
};

int main()
{

    Solution obj;

    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << obj.change(amount, coins);

    return 0;
}
// https://leetcode.com/problems/divisor-game/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool f(int x, int n, vector<int> &dp)
    {
        if (n < 1)
        {
            return false;
        }
        if (n == 1)
        {
            if (x % 2 != 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        for (int i = 1; i * i <= n; i++)
        {
            if (x % i == 0)
            {
                return dp[n] = f(x + 1, n - i, dp);
            }
        }

        return dp[n] = false;
    }

    bool divisorGame(int n)
    {
        vector<int> dp(n + 1, -1);
        return f(0, n, dp);
    }
};

int main()
{

    Solution obj;

    cout << obj.divisorGame(10) << endl;

    return 0;
}
// https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/description/

#include <bitsstdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, int> dp;
    int f(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        if (dp.find(n) != dp.end())
        {
            return dp[n];
        }
        int div2 = INT_MAX, div3 = INT_MAX;

        div2 = 1 + n % 2 + f(n / 2);
        div3 = 1 + n % 3 + f(n / 3);

        return dp[n] = min(div2, div3);
    }

    int minDays(int n)
    {
        return f(n);
    }
};

int main()
{

    Solution obj;

    cout << obj.minDays(10);

    return 0;
}
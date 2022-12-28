// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <bitsstdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = INT_MAX, maxi = 0;
        for (auto &x : prices)
        {
            maxi = max(maxi, x - mini);
            mini = min(x, mini);
        }

        return maxi < 0 ? 0 : maxi;
    }
};

int main()
{
    Solution obj;

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << obj.maxProfit(prices);

    return 0;
}
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> front(2, 0);
        int profit = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            curr[1] = max(-prices[ind] + front[0], 0 + front[1]);
            curr[0] = max(prices[ind] - fee + front[1], 0 + front[0]);

            front = curr;
        }

        return curr[1];
    }
};

int main()
{

    Solution obj;

    vector<int> prices = {1, 3, 2, 8, 4, 9};

    cout << obj.maxProfit(prices, 2);

    return 0;
}
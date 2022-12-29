// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<int> front2(2, 0);
        vector<int> front1(2, 0);
        vector<int> curr(2, 0);

        for (int ind = n - 1; ind >= 0; ind--)
        {
            curr[1] = max(-prices[ind] + front1[0], 0 + front1[1]);

            curr[0] = max(prices[ind] + front2[1], 0 + front1[0]);

            front2 = front1;
            front1 = curr;
        }

        return curr[1];
    }
};

int main()
{

    Solution obj;

    vector<int> prices = {1, 2, 3, 0, 2};

    cout << obj.maxProfit(prices);

    return 0;
}
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    if (buy)
                    {
                        curr[buy][cap] = max(-prices[ind] + after[0][cap], 0 + after[1][cap]);
                    }
                    else
                    {
                        curr[buy][cap] = max(prices[ind] + after[1][cap - 1], 0 + after[0][cap]);
                    }
                }
            }

            after = curr;
        }

        return curr[1][2];
    }
};

int main()
{
    Solution obj;

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    cout << obj.maxProfit(prices);

    return 0;
}
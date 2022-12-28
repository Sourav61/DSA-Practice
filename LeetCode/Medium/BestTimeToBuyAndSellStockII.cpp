// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        int st, end;
        int flag = 1;
        int n = prices.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (flag)
            {
                if (prices[i] < prices[i + 1])
                {
                    flag = 0;
                    st = i;
                }
            }
            else
            {
                if (prices[i] > prices[i + 1])
                {
                    flag = 1;
                    end = i;
                    ans += prices[end] - prices[st];
                }
            }
        }

        if (flag == 0)
        {
            ans += prices[n - 1] - prices[st];
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << obj.maxProfit(prices);

    return 0;
}
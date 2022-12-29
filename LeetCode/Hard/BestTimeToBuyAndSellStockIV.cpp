// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(int K, vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<int>> after(2, vector<int>(K + 1, 0));
        vector<vector<int>> curr(2, vector<int>(K + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= K; cap++)
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

        return curr[1][K];

        // =======================      Alternate Approach(TC: O(N*2*K), SC: O(2*K))      =============================

        // int n = prices.size();

        // vector<int> curr(K*2 + 1,0);
        // vector<int> after(K*2 + 1,0);

        // for(int ind=n-1;ind>=0;ind--){
        //     for(int tN=0;tN<=K*2-1;tN++){
        //         if(tN % 2 == 0){
        //             curr[tN] = max(-prices[ind] + after[tN+1], 0 + after[tN]);
        //         }else{
        //             curr[tN] = max(prices[ind] + after[tN+1], 0 + after[tN]);
        //         }
        //     }
        //     after = curr;
        // }

        // return curr[0];
    }
};

int main()
{

    Solution obj;

    vector<int> prices = {2, 4, 1};

    cout << obj.maxProfit(2, prices);

    return 0;
}
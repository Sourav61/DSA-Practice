// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        int n = prices.size();

        long long count = 0;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                mp[0] = 0;
            }
            else
            {
                if (prices[i - 1] - prices[i] == 1)
                {
                    mp[i] += mp[i - 1] + 1;
                }
                else
                {
                    mp[i] = 0;
                }
            }
        }

        for (auto i : mp)
        {
            count += i.second;
        }

        return (count + n);
    }
};

int main()
{
    Solution obj;

    vector<int> prices = {3, 2, 1, 4};

    cout << obj.getDescentPeriods(prices) << endl;

    return 0;
}
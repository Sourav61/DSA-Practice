// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int left = 0, right = 0;
        for (int i = 0; i < n; i++)
        {
            left = max(left, weights[i]);
            right += weights[i];
        }

        while (left < right)
        {
            int mid = (left + right) / 2;
            int need = 1, cur = 0;
            for (int i = 0; i < n && need <= days; i++)
            {
                cur += weights[i];
                if (cur > mid)
                {
                    cur = weights[i];
                    need++;
                }
            }

            if (need > days)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};

int main()
{

    Solution obj;

    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    cout << obj.shipWithinDays(weights, days) << endl;

    return 0;
}
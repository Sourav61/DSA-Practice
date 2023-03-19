// https://leetcode.com/problems/koko-eating-bananas/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int maxi = INT_MIN;
        for (auto &x : piles)
        {
            maxi = max(maxi, x);
        }
        if (h == piles.size())
            return maxi;

        int low = 1, high = maxi;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long int time = 0;

            for (auto &x : piles)
            {
                time += (long long int)(ceil(x * 1.0 / mid));
            }

            if (time <= h)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main()
{

    Solution obj;

    vector<int> piles = {3, 6, 7, 11};

    cout << obj.minEatingSpeed(piles, 8);

    return 0;
}
// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        int maxi = INT_MIN;
        for (auto &x : candies)
        {
            maxi = max(maxi, x);
        }
        int low = 1, high = maxi;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long temp = 0;
            for (auto &x : candies)
            {
                temp += (x / mid);
            }

            if (temp >= k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low - 1;
    }
};

int main()
{

    Solution obj;
    vector<int> candies = {5, 8, 6};

    cout << obj.maximumCandies(candies, 3);

    return 0;
}
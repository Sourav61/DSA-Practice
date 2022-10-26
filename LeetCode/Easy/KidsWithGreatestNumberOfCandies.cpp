// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> res;

        int n = candies.size();
        int maxi = 0;

        for (auto x : candies)
        {
            maxi = max(maxi, x);
        }

        for (auto x : candies)
        {
            if (x >= maxi - extraCandies)
            {
                res.push_back(1);
            }
            else
            {
                res.push_back(0);
            }
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> candies = {2, 3, 5, 1, 3};

    int extraCandies = 3;

    vector<bool> res = obj.kidsWithCandies(candies, extraCandies);

    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
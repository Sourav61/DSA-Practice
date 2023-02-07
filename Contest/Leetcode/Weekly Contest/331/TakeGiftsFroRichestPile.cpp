// https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        while (k--)
        {
            sort(gifts.begin(), gifts.end());
            long long temp = gifts[gifts.size() - 1];
            gifts.pop_back();

            gifts.push_back(floor(sqrt(temp)));
        }

        long long res = 0;

        for (auto &x : gifts)
        {
            res += x;
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> gifts = {25, 64, 9, 4, 100};

    cout << obj.pickGifts(gifts, 4);

    return 0;
}
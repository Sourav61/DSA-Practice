// https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> maxH;

        int sum = 0;

        for (auto &x : piles)
        {
            maxH.push(x);
            sum += x;
        }

        while (!maxH.empty() && k--)
        {
            auto node = maxH.top();
            maxH.pop();
            sum -= node / 2;
            maxH.push(node - node / 2);
        }

        return sum;
    }
};

int main()
{

    Solution obj;

    vector<int> piles = {5, 4, 9};

    cout << obj.minStoneSum(piles, 2);

    return 0;
}
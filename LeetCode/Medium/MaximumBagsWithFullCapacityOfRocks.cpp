// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        int n = rocks.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            rocks[i] = capacity[i] - rocks[i];
        }

        sort(rocks.begin(), rocks.end());

        for (int i = 0; i < n; i++)
        {
            if (additionalRocks >= rocks[i])
            {
                ans++;
                additionalRocks -= rocks[i];
                continue;
            }
            break;
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<int> capacity = {2, 3, 4, 5};
    vector<int> rocks = {1, 2, 4, 4};
    int additionalRocks = 2;

    cout << obj.maximumBags(capacity, rocks, additionalRocks);

    return 0;
}
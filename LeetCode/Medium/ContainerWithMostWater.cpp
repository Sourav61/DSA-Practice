// https://leetcode.com/problems/container-with-most-water/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = 0;
        int n = height.size();
        int f = 0, h = n - 1;

        while (f < h)
        {
            ans = max(ans, (h - f) * min(height[f], height[h]));

            if (height[f] > height[h])
            {
                h = h - 1;
            }
            else
            {
                f = f + 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << obj.maxArea(height);

    return 0;
}
// https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int averageValue(vector<int> &nums)
    {
        int cnt = 0, sum = 0;
        for (auto &x : nums)
        {
            if (x % 6 == 0)
            {
                cnt++;
                sum += x;
            }
        }

        return cnt == 0 ? 0 : (sum / cnt);
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 3, 6, 10, 12, 15};

    cout << obj.averageValue(nums);

    return 0;
}
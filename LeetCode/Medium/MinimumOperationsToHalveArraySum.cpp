// https://leetcode.com/problems/minimum-operations-to-halve-array-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        priority_queue<double> maxH;

        double sum = 0;

        for (auto &x : nums)
        {
            maxH.push(x);
            sum += x;
        }

        double newSum = sum, cnt = 0;

        while (!maxH.empty() && newSum / 2 < sum)
        {
            auto node = maxH.top();
            maxH.pop();
            sum -= node / 2;
            maxH.push(node / 2);
            cnt++;
        }

        return cnt;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {5, 19, 8, 1};

    cout << obj.halveArray(nums);

    return 0;
}
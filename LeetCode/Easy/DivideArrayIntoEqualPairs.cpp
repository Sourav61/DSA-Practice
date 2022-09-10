// https://leetcode.com/problems/divide-array-into-equal-pairs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        int n = nums.size();

        priority_queue<int> maxH;

        for (auto x : nums)
            maxH.push(x);

        while (maxH.size() > 0)
        {
            int first = maxH.top();
            maxH.pop();
            int second = maxH.top();
            maxH.pop();

            if (first != second)
                return false;
        }

        return true;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {3, 2, 3, 2, 2, 2};

    cout << obj.divideArray(nums) << endl;

    return 0;
}
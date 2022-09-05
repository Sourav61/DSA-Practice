// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        unordered_set<int> s;
        for (auto i : nums)
            if (i != 0)
                s.insert(i);
        return s.size();
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 5, 0, 3, 5};

    cout << obj.minimumOperations(nums) << endl;

    return 0;
}
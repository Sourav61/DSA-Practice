// https://leetcode.com/contest/biweekly-contest-97/problems/separate-the-digits-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> res;
        for (auto &x : nums)
        {
            vector<int> temp;

            while (x)
            {
                temp.push_back(x % 10);
                x /= 10;
            }
            reverse(temp.begin(), temp.end());
            for (auto &v : temp)
                res.push_back(v);
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {13, 25, 83, 77};

    cout << obj.separateDigits(nums);

    return 0;
}
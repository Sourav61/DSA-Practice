// https://leetcode.com/problems/split-with-minimum-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int splitNum(int num)
    {
        vector<int> nums;

        while (num)
        {
            nums.push_back(num % 10);
            num /= 10;
        }

        sort(nums.begin(), nums.end());
        int a = 0, b = 0, i = 0;

        while (i < nums.size())
        {
            a = a * 10 + nums[i];
            i++;
            if (i < nums.size())
            {
                b = b * 10 + nums[i];
                i++;
            }
        }

        return a + b;
    }
};

int main()
{
    Solution obj;

    cout << obj.splitNum(4532);

    return 0;
}
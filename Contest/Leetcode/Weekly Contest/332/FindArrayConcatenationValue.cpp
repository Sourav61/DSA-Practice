// https://leetcode.com/problems/find-the-array-concatenation-value/description/

#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findTheArrayConcVal(vector<int> &nums)
    {
        int n = nums.size();
        int fs = 0, ls = n - 1;

        long long res = 0;
        while (fs <= ls)
        {
            string temp = "";
            if (fs == ls)
            {
                temp = to_string(nums[fs]);
            }
            else
                temp = to_string(nums[fs]) + to_string(nums[ls]);
            res += stoi(temp);
            fs++;
            ls--;
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {7, 52, 2, 4};

    cout << obj.findTheArrayConcVal(nums) << endl;

    return 0;
}
// https://leetcode.com/problems/product-of-array-except-self/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        int prod = 1;

        vector<int> res;
        int cnt = 0, idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                cnt++;
                if (cnt > 1)
                {
                    break;
                }
                idx = i;
            }
            else
            {
                prod *= nums[i];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (cnt > 1)
            {
                res.push_back(0);
            }
            else if (cnt == 1)
            {
                if (i == idx)
                {
                    res.push_back(prod);
                }
                else
                {
                    res.push_back(0);
                }
            }
            else
            {
                res.push_back(prod / nums[i]);
            }
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 2, 3, 4};

    vector<int> res = obj.productExceptSelf(nums);

    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
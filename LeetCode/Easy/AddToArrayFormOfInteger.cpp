// https://leetcode.com/problems/add-to-array-form-of-integer/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int n = num.size(), i = n - 1, carry = 0;

        while (i >= 0 || k > 0)
        {
            int res;
            if (i >= 0)
            {
                res = num[i] + (k % 10) + carry;
                num[i] = res % 10;
            }
            else
            {
                res = (k % 10) + carry;
                num.insert(num.begin(), res % 10);
            }
            carry = (res / 10);
            k /= 10;
            i--;
        }

        if (carry == 1)
        {
            num.insert(num.begin(), carry);
        }

        return num;
    }
};

int main()
{

    Solution obj;

    vector<int> num = {1, 2, 0, 1};

    vector<int> res = obj.addToArrayForm(num, 34);

    for (auto &x : res)
    {
        cout << x << " ";
    }

    return 0;
}
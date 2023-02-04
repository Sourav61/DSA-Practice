// https://leetcode.com/problems/reverse-integer/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long long int res = 0;
        while (x != 0)
        {
            res = res * 10 + x % 10;
            x = x / 10;
        }

        if (res - 1 >= -pow(2, 31) && res + 1 <= pow(2, 31))
        {
            return res;
        }

        return 0;
    }
};

int main()
{

    Solution obj;

    cout << obj.reverse(123);

    return 0;
}
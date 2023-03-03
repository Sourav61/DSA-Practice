// https://leetcode.com/problems/count-good-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = (int)(1e9 + 7);

    long long pow(long long x, long long n)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (n % 2 == 0)
        {
            long long y = pow(x, n / 2);
            return ((y * y) % mod);
        }
        return (x * pow(x, n - 1)) % mod;
    }

    int countGoodNumbers(long long n)
    {
        if (n == 1)
        {
            return 5;
        }

        long long odd = n / 2;
        long long even = n - odd;

        return ((long long)pow(4, odd) % mod * (long long)pow(5, even) % mod);
    }
};

int main()
{

    Solution obj;

    cout << obj.countGoodNumbers(300000);

    return 0;
}
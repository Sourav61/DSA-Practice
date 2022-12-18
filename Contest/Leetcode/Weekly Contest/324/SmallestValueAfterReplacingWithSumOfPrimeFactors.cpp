// https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/description

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find(int n)
    {
        int sum = 0;
        while (n % 2 == 0)
        {
            sum += 2;
            n /= 2;
        }
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            while (n % i == 0)
            {
                sum += i;
                n /= i;
            }
        }

        if (n > 2)
        {
            sum += n;
        }

        return sum;
    }

    int smallestValue(int n)
    {
        int res = INT_MAX;
        while (res != find(n))
        {
            res = find(n);
            n = res;
        }

        return n;
    }
};

int main()
{

    Solution obj;

    cout << obj.smallestValue(5);

    return 0;
}
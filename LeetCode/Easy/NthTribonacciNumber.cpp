// https://leetcode.com/problems/n-th-tribonacci-number/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        int prev3 = 0;
        int prev2 = 1;
        int prev = 1;

        for (int i = 3; i <= n; i++)
        {
            int curi = prev3 + prev2 + prev;
            prev3 = prev2;
            prev2 = prev;
            prev = curi;
        }

        return prev;
    }
};

int main()
{
    Solution obj;

    cout << obj.tribonacci(4);

    return 0;
}
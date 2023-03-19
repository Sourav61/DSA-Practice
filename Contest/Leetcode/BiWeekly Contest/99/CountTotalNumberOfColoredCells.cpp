// https://leetcode.com/problems/count-total-number-of-colored-cells/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long coloredCells(int n)
    {
        long long res = 1;

        for (int i = 2; i <= n; i++)
        {
            res += (i - 1) * 4;
        }

        return res;
    }
};

int main()
{

    Solution obj;

    cout << obj.coloredCells(20);

    return 0;
}
// https://leetcode.com/problems/ugly-number/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isUgly(int n)
    {
        for (int i = 2; i < 6 && n; i++)
            while (n % i == 0)
                n /= i;
        return n == 1;
    }
};

int main()
{

    Solution obj;

    cout << obj.isUgly(n) << endl;

    return 0;
}
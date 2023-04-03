// https://leetcode.com/problems/minimum-operations-to-make-array-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(int n)
    {
        return n % 2 == 0 ? (n / 2 * ((n + 1) / 2)) : (n / 2 * ((n + 2) / 2));
    }
};

int main()
{

    Solution obj;

    cout << obj.minOperations(6);

    return 0;
}
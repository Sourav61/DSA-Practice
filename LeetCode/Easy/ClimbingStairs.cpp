// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        long long int prev2 = 1;
        long long int prev = 1;

        for (int i = 2; i <= n; i++)
        {
            long long int curi = (prev + prev2);
            prev2 = prev;
            prev = curi;
        }

        return prev;
    }
};

int main()
{
    Solution obj;

    cout << obj.climbStairs(3);

    return 0;
}
// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

#include <bits/stdc+++.h>
using namespace std;

class Solution
{
public:
    int countOdds(int low, int high)
    {
        if (low % 2 == 0 && high % 2 == 0)
        {
            return (high - low) / 2;
        }

        if (low % 2 != 0 && high % 2 != 0)
        {
            return (high - low) / 2 + 1;
        }

        return (high - low) / 2 + 1;
    }
};

int main()
{

    Solution obj;

    cout << obj.countOdds(3, 10);

    return 0;
}
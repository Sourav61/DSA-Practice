// https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/submissions/850180147/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfCuts(int n)
    {
        if (n <= 1)
        {
            return 0;
        }
        if (n % 2 == 0)
        {
            return n / 2;
        }

        return n;
    }
};

int main()
{
    Solution obj;

    cout << obj.numberOfCuts(7);

    return 0;
}
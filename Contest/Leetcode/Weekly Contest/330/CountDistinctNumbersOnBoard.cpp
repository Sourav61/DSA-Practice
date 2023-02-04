// https://leetcode.com/contest/weekly-contest-330/problems/count-distinct-numbers-on-board/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distinctIntegers(int n)
    {
        if (n == 1)
        {
            return n;
        }
        return n - 1;
    }
};

int main()
{

    Solution obj;

    cout << obj.distinctIntegers(4);

    return 0;
}
// https://leetcode.com/problems/number-of-1-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                ans++;
            }
            n = n >> 1;
        }
        return ans;
    }
};

int main()
{
    Solution obj;

    string num = "00000000000000000000000000001011";

    cout << obj.hammingWeight(num);

    return 0;
}
// https://leetcode.com/problems/flip-string-to-monotone-increasing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int min_flips = 0;
        int num_ones = 0;

        for (auto &x : s)
        {
            if (x == '1')
                num_ones++;
            else if (num_ones > 0)
            {
                min_flips++;
                num_ones--;
            }
        }

        return min_flips;
    }
};

int main()
{

    Solution obj;

    cout << obj.minFlipsMonoIncr("00110");

    return 0;
}
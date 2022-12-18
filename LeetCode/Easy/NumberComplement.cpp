// https://leetcode.com/problems/number-complement/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findComplement(int num)
    {
        int i = 0, n = num;
        while (num > 0)
        {
            if (num % 2 != 0)
            {
                n -= pow(2, i);
            }
            else
            {
                n += pow(2, i);
            }
            num /= 2;
            i++;
        }

        return n;
    }
};

int main()
{

    Solution obj;

    cout << obj.findComplement(5);

    return 0;
}
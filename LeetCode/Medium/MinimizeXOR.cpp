// https://leetcode.com/problems/minimize-xor/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int setBits(int n)
    {
        int cnt = 0;

        while (n > 0)
        {
            if ((n & 1) != 0)
            {
                cnt++;
            }

            n /= 2;
        }

        return cnt;
    }

    int minimizeXor(int a, int b)
    {
        int sb1 = setBits(a);
        int sb2 = setBits(b);

        if (sb1 == sb2)
        {
            return a;
        }

        int res = 0;

        for (int i = 0; i < 32; i++)
        {
            int mask = 1 << i;
            int setBit = a & mask;

            if (setBit == 0 && sb1 < sb2)
            {
                res = res | mask;
                sb2--;
            }
            else if (setBit != 0 && sb1 > sb2)
            {
                sb1--;
            }
            else
            {
                res = res | setBit;
            }
        }

        return res;
    }
};

int main()
{

    Solution obj;

    cout << obj.minimizeXor(3, 5);

    return 0;
}
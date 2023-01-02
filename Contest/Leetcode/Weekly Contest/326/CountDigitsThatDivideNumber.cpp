// https://leetcode.com/problems/count-the-digits-that-divide-a-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countDigits(int num)
    {
        int res = 0;

        int temp = num;
        while (temp)
        {
            if (num % (temp % 10) == 0)
                res++;
            temp /= 10;
        }
        return res;
    }
};

int main()
{

    Solution obj;

    cout << obj.countDigits(121);

    return 0;
}
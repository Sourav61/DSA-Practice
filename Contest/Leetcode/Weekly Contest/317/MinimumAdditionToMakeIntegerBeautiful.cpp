// https://leetcode.com/contest/weekly-contest-317/problems/minimum-addition-to-make-integer-beautiful/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long makeIntegerBeautiful(long long n, int target)
    {
        long long res = 0;
        long long temp = n;
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }

        int level = 0;

        while (sum > target)
        {
            if (temp % 10 == 0)
            {
                level++;
                temp /= 10;
            }
            else
            {
                int toAdd = 10 - (temp % 10);
                temp += toAdd;
                n = temp;
                sum = 0;
                while (n)
                {
                    sum += n % 10;
                    n /= 10;
                }
                res += pow(10, level) * toAdd;
            }
        }

        return res;
    }
};

int main()
{
    Solution obj;

    cout << obj.makeIntegerBeautiful(1467, 5);

    return 0;
}
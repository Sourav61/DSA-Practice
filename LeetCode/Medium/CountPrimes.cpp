// https://leetcode.com/problems/count-primes/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;
        vector<bool> seen(n, false);

        int count = 0;

        for (int i = 2; i < n; i++)
        {
            if (seen[i])
                continue;

            count++;

            for (long mult = (long)i * i; mult < n; mult += i)
                seen[mult] = true;
        }

        return count;
    }
};

int main()
{

    Solution obj;

    cout << obj.countPrimes(10) << endl;

    return 0;
}
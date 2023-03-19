// https://leetcode.com/problems/number-of-even-and-odd-bits/description

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> evenOddBit(int n)
    {
        vector<int> res;

        while (n)
        {
            res.push_back(n % 2);
            n /= 2;
        }

        int odd = 0, even = 0;
        n = res.size();

        for (int i = 0; i < n; i++)
        {
            if ((i % 2) == 0 && res[i] == 1)
            {
                even++;
            }
            else if ((i % 2) != 0 && res[i] == 1)
            {
                odd++;
            }
        }

        return {even, odd};
    }
};

int main()
{

    Solution obj;

    cout << obj.evenOddBit(17);

    return 0;
}
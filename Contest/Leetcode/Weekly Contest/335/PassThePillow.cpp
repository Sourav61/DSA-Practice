// https://leetcode.com/problems/pass-the-pillow/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int passThePillow(int n, int time)
    {
        if ((time / (n - 1)) % 2 != 0)
        {
            return n - ((time) % (n - 1));
        }

        return (time % (n - 1)) + 1;
    }
};

int main()
{

    Solution obj;

    cout << obj.passThePillow(4, 5);

    return 0;
}
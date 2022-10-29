#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTime(string time)
    {
        int cnt = 1;
        if (time[0] == '?' && time[1] == '?')
        {
            cnt *= 24;
        }
        else if (time[0] == '?')
        {
            if (time[1] - '0' > 3)
            {
                cnt *= 2;
            }
            else
            {
                cnt *= 3;
            }
        }
        else if (time[1] == '?')
        {
            if (time[0] - '0' == 2)
            {
                cnt *= 4;
            }
            else
            {
                cnt *= 10;
            }
        }
        if (time[3] == '?')
        {
            cnt *= 6;
        }
        if (time[4] == '?')
        {
            cnt *= 10;
        }

        return cnt;
    }
};

int main()
{
    Solution obj;

    cout << obj.countTime("?0:0?");

    return 0;
}
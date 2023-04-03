// https://leetcode.com/problems/can-place-flowers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &fb, int n)
    {
        if (n == 0)
        {
            return true;
        }
        if (fb.size() == 1)
        {
            return fb[0] == 0 && n == 1;
        }

        for (int i = 0; i < fb.size(); i += 2)
        {
            if (fb[i] == 1)
            {
                continue;
            }

            if (i == 0)
            {
                if (fb[i + 1] == 0)
                {
                    fb[i] = 1;
                    n--;
                }
            }
            else if (i == fb.size() - 1)
            {
                if (fb[i - 1] == 0)
                {
                    fb[i] = 1;
                    n--;
                }
            }
            else
            {
                if (fb[i - 1] == 0 && fb[i + 1] == 0)
                {
                    fb[i] = 1;
                    n--;
                }
            }
            if (n == 0)
            {
                return true;
            }
        }

        if (fb.size() % 2 == 0)
        {
            if (fb[fb.size() - 1] == 0 && fb[fb.size() - 2] == 0)
            {
                n--;
            }
            if (n == 0)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{

    Solution obj;

    vector<int> fb = {1, 0, 0, 0, 1};

    cout << obj.canPlaceFlowers(fb, 1);

    return 0;
}
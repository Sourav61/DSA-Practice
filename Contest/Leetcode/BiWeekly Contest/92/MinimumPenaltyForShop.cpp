// https://leetcode.com/contest/biweekly-contest-92/problems/minimum-penalty-for-a-shop/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        unordered_map<int, int> mpN, mpC;

        int n = customers.length();

        int mini = INT_MAX, minIdx = 0;

        for (int i = 1; i <= n; i++)
        {
            mpN[i] = mpN[i - 1];

            if (customers[i - 1] == 'N')
            {
                mpN[i]++;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            mpC[i] = mpC[i + 1];
            if (customers[i] == 'Y')
            {
                mpC[i]++;
            }
        }

        for (int i = 0; i <= n; i++)
        {
            // cout<<mpN[i]<<" "<<mpC[i]<<endl;
            if (mpN[i] + mpC[i] < mini)
            {
                mini = mpN[i] + mpC[i];
                minIdx = i;
            }
        }

        return minIdx;
    }
};

int main()
{
    Solution obj;

    cout << obj.bestClosingTime("YYNY");

    return 0;
}
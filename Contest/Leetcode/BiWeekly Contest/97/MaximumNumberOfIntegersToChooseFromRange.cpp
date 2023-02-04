// https://leetcode.com/contest/biweekly-contest-97/problems/maximum-number-of-integers-to-choose-from-a-range-i//

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        unordered_map<int, int> mp;

        int sum = 0;
        for (auto &x : banned)
        {
            mp[x] = 1;
        }

        int cnt = 0;

        for (int i = 1; i <= n; i++)
        {

            if (mp[i] == 0)
            {
                sum += i;
                if (sum <= maxSum)
                    cnt++;
            }
        }

        return cnt;
    }
};

int main()
{

    Solution obj;

    vector<int> banned = {1, 6, 5};

    cout << obj.maxCount(banned, 5, 6);

    return 0;
}
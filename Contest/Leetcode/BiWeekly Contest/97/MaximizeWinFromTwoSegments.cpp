// https://leetcode.com/problems/maximize-win-from-two-segments/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximizeWin(vector<int> &prizePositions, int k)
    {
        int n = prizePositions.size(), res = 0, j = 0;
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            while (prizePositions[i] - prizePositions[j] > k)
            {
                j++;
            }

            dp[i + 1] = max(dp[i], i - j + 1);
            res = max(res, i - j + 1 + dp[j]);
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> prizePositions = {1, 1, 2, 2, 3, 3, 5};

    cout << obj.maximizeWin(prizePositions, 2);

    return 0;
}
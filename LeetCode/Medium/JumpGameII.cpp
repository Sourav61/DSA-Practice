// https://leetcode.com/problems/jump-game-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &arr)
    {
        int n = arr.size();
        if (arr[0] == 0 && n > 1)
            return -1;

        if (n == 1)
            return 0;

        int steps = arr[0];
        int maxReach = arr[0];
        int jumps = 1;

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
                return jumps;

            if (steps)
            {
                maxReach = max(maxReach, arr[i] + i);
                steps--;
            }

            if (steps == 0)
            {
                if (i >= maxReach)
                    return -1;
                jumps++;
                steps = maxReach - i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {2, 3, 1, 1, 4};

    cout << obj.jump(arr);

    return 0;
}
// https://leetcode.com/problems/maximize-distance-to-closest-person/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int n = seats.size();
        int empty = 0;
        int res = 0;
        int left = -1, right = -1;

        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 1)
            {
                empty = 0;
                if (left == -1)
                    left = i;
                right = i;
            }
            else
            {
                empty++;
                res = max(res, (empty + 1) / 2);
            }
        }

        res = max({res, left, n - 1 - right});

        return res;
    }
};

int main()
{

    vector<int> seats = {0, 1};

    Solution obj;

    cout << obj.maxDistToClosest(seats) << endl;

    return 0;
}
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int n = points.size();

        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        int take = 1;
        int end = points[0][1];

        for (int i = 0; i < n; i++)
        {
            if (points[i][0] > end)
            {
                take++;
                end = points[i][1];
            }
        }

        return take;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};

    cout << obj.findMinArrowShots(points) << endl;

    return 0;
}
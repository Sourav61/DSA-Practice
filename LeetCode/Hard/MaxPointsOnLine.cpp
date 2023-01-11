// https://leetcode.com/problems/max-points-on-a-line/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int res = 1;
        unordered_map<double, int> mp;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (points[i][0] == points[j][0])
                {
                    mp[1000001]++;
                }
                else
                {
                    double slope = (double)(points[j][1] - points[i][1]) / (double)(points[j][0] - points[i][0]);
                    mp[slope]++;
                }
            }

            int temp = 0;

            for (auto &x : mp)
            {
                temp = max(temp, x.second);
            }

            res = max(res, temp + 1);
            mp.clear();
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> points = {{1, 1},
                                  {2, 2},
                                  {3, 3}};

    cout << obj.maxPoints(points);

    return 0;
}
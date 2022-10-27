// https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        res.push_back(intervals[0]);

        int j = 0;
        int n = intervals.size();

        for (int i = 1; i < n; i++)
        {
            if (res[j][1] >= intervals[i][0])
            {
                res[j][1] = max(intervals[i][1], res[j][1]);
            }
            else if (res[j][1] < intervals[i][0])
            {
                res.push_back(intervals[i]);
                j++;
            }
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> res = obj.merge(intervals) << endl;

    for (auto v : res)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
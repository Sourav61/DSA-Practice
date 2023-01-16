// https://leetcode.com/problems/insert-interval/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size();
        vector<vector<int>> res;

        if (n == 0)
        {
            res.push_back(newInterval);
            return res;
        }

        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (intervals[mid][0] < newInterval[0])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        while (high >= 0 && intervals[high][1] >= newInterval[0])
        {
            newInterval[0] = min(newInterval[0], intervals[high][0]);
            newInterval[1] = max(newInterval[1], intervals[high][1]);
            high--;
        }

        while (low < n && intervals[low][0] <= newInterval[1])
        {
            newInterval[1] = max(newInterval[1], intervals[low][1]);
            low++;
        }

        int i = 0;
        while (high >= 0 && i <= high)
        {
            res.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }

        res.push_back({newInterval[0], newInterval[1]});

        i = low;

        while (i < n)
        {
            res.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> temp = {{1, 3}, {6, 9}};

    vector<int> newInterval = {2, 5};

    vector<vector<int>> res = obj.insert(temp, newInterval);

    for (auto &v : res)
    {
        for (auto &x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
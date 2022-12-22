// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[1] < b[1])
        {
            return true;
        }
        else if (a[1] == b[1])
        {
            return a[0] < b[0];
        }

        return false;
    }

    int maxEvents(vector<vector<int>> &events)
    {
        int n = events.size();
        sort(events.begin(), events.end(), cmp);

        int cnt = 0;
        set<int> days;

        for (int i = 0; i <= 100000; i++)
        {
            days.insert(i);
        }

        for (auto &x : events)
        {
            int start = x[0], end = x[1];
            auto it = days.lower_bound(start);

            if (it == days.end() || *it > end)
            {
                continue;
            }
            else
            {
                cnt++;
                days.erase(it);
            }
        }

        return cnt;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}};

    cout << obj.maxEvents(events);

    return 0;
}
// https://leetcode.com/problems/single-threaded-cpu/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minH;
        vector<int> res;
        int n = tasks.size();
        long time = 0;

        int i = 0;

        for (auto &x : tasks)
        {
            x.push_back(i);
            i++;
        }

        sort(tasks.begin(), tasks.end());
        i = 0;

        while (i < n || !minH.empty())
        {
            if (minH.empty())
            {
                time = max(time, (long)tasks[i][0]);
            }

            while (i < n && time >= tasks[i][0])
            {
                minH.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            auto curr = minH.top();
            minH.pop();

            time += curr.first;

            res.push_back(curr.second);
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};

    cout << obj.getOrder(tasks);

    return 0;
}
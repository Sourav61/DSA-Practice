// https://leetcode.com/problems/shortest-path-with-alternating-colors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<int> adjR[n];
        vector<int> adjB[n];

        for (auto &x : redEdges)
        {
            adjR[x[0]].push_back(x[1]);
        }
        for (auto &x : blueEdges)
        {
            adjB[x[0]].push_back(x[1]);
        }

        vector<pair<int, int>> graph(n, {INT_MAX, INT_MAX});
        graph[0] = {0, 0};

        queue<pair<int, char>> q;
        q.push({0, 'R'});
        q.push({0, 'B'});

        int ans = 0;

        while (!q.empty())
        {
            int sz = q.size();

            for (int i = 0; i < sz; i++)
            {
                auto curr = q.front();
                q.pop();

                int node = curr.first;
                char color = curr.second;

                if (color == 'R')
                {
                    for (auto &x : adjB[node])
                    {
                        if (graph[x].first > ans + 1)
                        {
                            graph[x].first = ans + 1;
                            q.push({x, 'B'});
                        }
                    }
                }
                else
                {
                    for (auto &x : adjR[node])
                    {
                        if (graph[x].second > ans + 1)
                        {
                            graph[x].second = ans + 1;
                            q.push({x, 'R'});
                        }
                    }
                }
            }
            ans++;
        }
        vector<int> res;

        for (auto &x : graph)
        {
            int mini = min(x.first, x.second);
            res.push_back(mini == INT_MAX ? -1 : mini);
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> redEdges = {{0, 1}, {1, 2}};
    vector<vector<int>> blueEdges = {};

    vector<int> res = obj.shortestAlternatingPaths(3, redEdges, blueEdges);

    for (auto &x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
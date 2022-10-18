// https://leetcode.com/problems/course-schedule-iv/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<vector<bool>> &check, vector<bool> &vis, int src, int node)
    {
        vis[node] = 1;
        check[src][node] = 1;

        for (auto &x : adj[node])
        {
            if (!vis[x])
            {
                dfs(adj, check, vis, src, x);
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<vector<bool>> check(numCourses, vector<bool>(numCourses, false));

        vector<vector<int>> adj(numCourses);

        for (auto &x : prerequisites)
        {
            adj[x[0]].push_back(x[1]);
            check[x[0]][x[1]] = true;
        }

        for (int i = 0; i < numCourses; i++)
        {
            vector<bool> vis(numCourses, false);
            dfs(adj, check, vis, i, i);
        }

        vector<bool> res;
        for (auto &x : queries)
        {
            res.push_back(check[x[0]][x[1]]);
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> prerequisites{{1, 0}};
    vector<vector<int>> queries{{0, 1}, {1, 0}};

    vector<bool> res = obj.checkIfPrerequisite(2, prerequisites, queries);

    for (auto x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}
// https://leetcode.com/problems/all-paths-from-source-to-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, int dest, vector<vector<int>> &graph, vector<vector<int>> &res, vector<int> &path)
    {
        path.push_back(node);
        if (node == dest)
        {
            res.push_back(path);
            return;
        }

        for (auto &x : graph[node])
        {
            dfs(x, dest, graph, res, path);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> temp;
        if (n == 0)
        {
            return res;
        }

        dfs(0, n - 1, graph, res, temp);

        return res;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};

    vector<vector<int>> res = obj.allPathsSourceTarget(graph);

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
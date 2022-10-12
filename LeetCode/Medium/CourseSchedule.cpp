// https://leetcode.com/problems/course-schedule/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[numCourses];

        for (auto x : prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }

        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            for (auto x : adj[i])
            {
                indegree[x]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto x : adj[node])
            {
                indegree[x]--;

                if (indegree[x] == 0)
                    q.push(x);
            }
        }

        if (topo.size() == numCourses)
            return true;

        return false;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> prerequisites = {{1, 0}};

    cout << obj.canFinish(2, prerequisites);

    return 0;
}
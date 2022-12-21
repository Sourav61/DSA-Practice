// https://leetcode.com/problems/possible-bipartition/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<int> adj[n + 1];

        for (auto &x : dislikes)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int> color(n + 1, -1);
        queue<int> q;

        for (int i = 1; i <= n; i++)
        {
            if (color[i] == -1 && adj[i].size() > 0)
            {
                color[i] = 0;
                q.push(i);

                while (!q.empty())
                {
                    int curr = q.front();

                    q.pop();

                    for (int j = 0; j < adj[curr].size(); j++)
                    {
                        int node = adj[curr][j];

                        if (color[node] != -1 && color[curr] == color[node])
                        {
                            return false;
                        }
                        else if (color[node] != -1 && color[node] != color[curr])
                            continue;

                        color[node] = !color[curr];

                        q.push(node);
                    }
                }
            }
        }

        return true;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};

    cout << obj.possibleBipartition(4, dislikes);

    return 0;
}
// https://leetcode.com/problems/keys-and-rooms/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();

        vector<bool> vis(n, false);
        vector<int> adj[n + 1];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < rooms[i].size(); j++)
            {
                adj[i].push_back(rooms[i][j]);
            }
        }

        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            vis[curr] = true;

            for (auto &x : adj[curr])
            {
                if (!vis[x])
                {
                    q.push(x);
                }
            }
        }

        for (auto x : vis)
        {
            if (x == false)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};

    cout << obj.canVisitAllRooms(rooms);

    return 0;
}
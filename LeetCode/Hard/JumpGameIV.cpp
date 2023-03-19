// https://leetcode.com/problems/jump-game-iv/description/

#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();

        if (n == 1)
        {
            return 0;
        }

        vector<int> vis(n + 1, -1);
        unordered_map<int, vector<int>> mp;

        for (int i = n - 1; i >= 0; i--)
        {
            mp[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = 0;

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            int idx = curr.first;
            int stps = curr.second;

            if (idx == n - 1)
            {
                return stps;
            }

            for (auto &x : mp[arr[idx]])
            {
                if (vis[x] == -1 || stps + 1 < vis[x])
                {
                    vis[x] = stps + 1;
                    q.push({x, stps + 1});
                }
            }

            if (vis[idx + 1] == -1 || stps + 1 < vis[idx + 1])
            {
                vis[idx + 1] = stps + 1;
                q.push({idx + 1, stps + 1});
            }

            if (idx - 1 >= 0 && (vis[idx - 1] == -1 || stps + 1 < vis[idx - 1]))
            {
                vis[idx - 1] = stps + 1;
                q.push({idx - 1, stps + 1});
            }

            mp.erase(arr[idx]);
        }

        return -1;
    }
};

int main()
{

    Solution obj;
    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};

    cout << obj.minJumps(arr);

    return 0;
}
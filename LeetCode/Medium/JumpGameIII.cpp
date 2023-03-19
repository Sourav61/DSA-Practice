// https://leetcode.com/problems/jump-game-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        if (n == 1)
        {
            return arr[0] == 0;
        }

        vector<int> vis(n + 1, -1);

        queue<int> q;
        q.push(start);

        vis[start] = 0;

        while (!q.empty())
        {
            auto idx = q.front();
            q.pop();

            if (arr[idx] == 0)
            {
                return 1;
            }

            if (idx + arr[idx] < n && vis[idx + arr[idx]] == -1)
            {
                vis[idx + arr[idx]] = 1;
                q.push(idx + arr[idx]);
            }

            if (idx - arr[idx] >= 0 && vis[idx - arr[idx]] == -1)
            {
                vis[idx - arr[idx]] = 1;
                q.push(idx - arr[idx]);
            }
        }

        return 0;
    }
};

int main()
{

    Solution obj;
    vector<int> arr = {4, 2, 3, 0, 3, 1, 2};

    cout << obj.canReach(arr, 2);

    return 0;
}
// https://leetcode.com/problems/path-with-minimum-effort/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<int, pair<int, int>> pipii;
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        priority_queue<pipii, vector<pipii>, greater<pipii>> minH;

        dist[0][0] = 0;
        minH.push({0, {0, 0}});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        while (!minH.empty())
        {
            auto temp = minH.top();
            minH.pop();

            int diff = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            if (row == n - 1 && col == m - 1)
                return diff;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                    if (newEffort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = newEffort;
                        minH.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }

        return 0;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> heights{{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    cout << obj.minimumEffortPath(heights);

    return 0;
}
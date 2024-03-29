// https://leetcode.com/problems/flood-fill/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> image,
             int newColor, int delrow[], int delcol[], int init)
    {
        ans[row][col] = newColor;

        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == init && ans[nrow][ncol] != newColor)
            {
                dfs(nrow, ncol, ans, image, newColor, delrow, delcol, init);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int initColor = image[sr][sc];
        vector<vector<int>> ans = image;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        dfs(sr, sc, ans, image, newColor, delrow, delcol, initColor);

        return ans;
    }
};

int main()
{

    Solution obj;

    vector<vector<int>> image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

    vector<vector<int>> res = obj.floodFill(image, 1, 1, 2);

    for (auto v : res)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
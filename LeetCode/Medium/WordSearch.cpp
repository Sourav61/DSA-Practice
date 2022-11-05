// https://leetcode.com/problems/word-search/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int row, int col, vector<vector<char>> &board, string word, vector<vector<int>> &vis, int cur, int n, int m)
    {
        if (cur == word.length())
        {
            return true;
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == word[cur] && !vis[nrow][ncol])
            {
                cur++;
                vis[nrow][ncol] = 1;

                if (dfs(nrow, ncol, board, word, vis, cur, n, m))
                {
                    return true;
                }
                cur--;
                vis[nrow][ncol] = 0;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    vis[i][j] = 1;
                    if (dfs(i, j, board, word, vis, 1, n, m))
                    {
                        return true;
                    }
                    else
                    {
                        vis[i][j] = 0;
                    }
                }
            }
        }

        return false;
    }
};

int main()
{

    Solution obj;

    vector<vector<char>> board{{"A", "B", "C", "E"}, {"S", "F", "C", "S"}, {"A", "D", "E", "E"}};
    string word = "ABCCED";

    cout << obj.exist(board, word);

    return 0;
}
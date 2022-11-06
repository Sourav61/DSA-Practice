// https://practice.geeksforgeeks.org/problems/word-boggle4143/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(int row, int col, vector<vector<char>> &board, string word, vector<vector<int>> &vis, int cur, int n, int m)
    {
        if (cur == word.length())
        {
            return true;
        }

        int delrow[] = {-1, 0, 1, 0, 1, -1, 1, -1};
        int delcol[] = {0, 1, 0, -1, 1, -1, -1, 1};

        vis[row][col] = 1;

        for (int i = 0; i < 8; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == word[cur] && !vis[nrow][ncol])
            {
                if (dfs(nrow, ncol, board, word, vis, cur + 1, n, m))
                {
                    return true;
                }
            }
        }
        vis[row][col] = 0;
        return false;
    }

    vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary)
    {
        int n = board.size();
        int m = board[0].size();
        vector<string> res;

        for (auto &word : dictionary)
        {
            bool flag = false;
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
                            res.push_back(word);
                            flag = true;
                        }
                        else
                        {
                            vis[i][j] = 0;
                        }
                    }
                    if (flag)
                    {
                        break;
                    }
                }
                if (flag)
                {
                    break;
                }
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i)
        {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }

        int R, C;
        cin >> R >> C;
        vector<vector<char>> board(R);
        for (int i = 0; i < R; i++)
        {
            board[i].resize(C);
            for (int j = 0; j < C; j++)
                cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else
        {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++)
                cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
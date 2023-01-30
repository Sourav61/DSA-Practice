// https://leetcode.com/problems/snakes-and-ladders/

class Solution
{
public:
    // int snakesAndLadders(vector<vector<int>> &board)
    // {
    //     queue<pair<pair<int, int>, int>> q;
    //     int n = board.size();

    //     int steps = 0;

    //     q.push({{n - 1, 0}, 0});

    //     int rolled = 6;

    //     while (!q.empty())
    //     {
    //         queue<pair<pair<int, int>, int>> tmp = q;

    //         while (!tmp.empty())
    //         {
    //             auto cur = tmp.front();
    //             tmp.pop();

    //             int stpss = cur.second;
    //             int i1 = cur.first.first;
    //             int j1 = cur.first.second;
    //             cout << i1 << " " << j1 << "  ";
    //         }
    //         cout << endl
    //              << endl;

    //         auto curr = q.front();
    //         q.pop();

    //         int stps = curr.second;
    //         int i = curr.first.first;
    //         int j = curr.first.second;

    //         // cout<<i<<" "<<j<<" "<<stps<<endl;

    //         // cout<<i<<" "<<j<<" "<<board[i][j]<<" "<<stps<<endl;

    //         if (i == 0 && j == n - 1)
    //         {
    //             return stps;
    //         }

    //         if (board[i][j] != -1)
    //         {
    //             int temp = board[i][j];
    //             i = (temp) / n;
    //             j = (temp) % n;
    //         }
    //         // cout<<i<<" "<<j<<" "<<board[i][j]<<" "<<stps<<endl;
    //         // if(i == 2 && j == 2){
    //         //     break;
    //         // }
    //         while (rolled--)
    //         {
    //             if (i >= n || j >= n)
    //                 break;

    //             // if(i == 0 || j == 0){

    //             // }
    //             if (i == n - 1 && j == 0)
    //             {
    //             }
    //             else if (j == 0 || (j + 1) % n == 0)
    //             {
    //                 i--;
    //                 j++;
    //             }

    //             if (i % 2 == 0)
    //             {
    //                 j--;
    //             }
    //             else
    //             {
    //                 j++;
    //             }

    //             q.push({{i, j}, stps + 1});
    //         }
    //     }

    //     return -1;
    // }

    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<int> q;
        q.push(1);
        vis[n - 1][0] = true;

        int steps = 0;

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int curr = q.front();
                q.pop();

                if (curr == n * n)
                {
                    return steps;
                }

                for (int roll = 1; roll <= 6; roll++)
                {
                    if (curr + roll > n * n)
                    {
                        break;
                    }

                    vector<int> pos = findCoordinates(curr + roll, n);
                    int row = pos[0];
                    int col = pos[1];
                    if (!vis[row][col])
                    {
                        vis[row][col] = true;
                        if (board[row][col] == -1)
                        {
                            q.push(curr + roll);
                        }
                        else
                        {
                            q.push(board[row][col]);
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }

    vector<int> findCoordinates(int currVal, int n)
    {
        int row = n - (currVal - 1) / n - 1;
        int col = (currVal - 1) % n;

        if (row % 2 == n % 2)
        {
            return {row, n - 1 - col};
        }
        else
        {
            return {row, col};
        }
    }
};
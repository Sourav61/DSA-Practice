// https://practice.geeksforgeeks.org/problems/hopscotch4857/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        const int x = ((j & 1) << 1) - 1;

        vector<pair<int, int>> oneDist = {

            {1, 0}, {-1, 0},

            {0, 1},
            {0, -1},

            // shifitng co-ordinate

            {x, -1},
            {x, 1}

        };

        vector<pair<int, int>> twoDist = {

            {1, 2}, {1, -2},

            {2, 0},
            {-2, 0},

            {0, 2},
            {0, -2},

            {-1, 2},
            {-1, -2},

            // shifting co-ordinate

            {2 * x, 1},
            {2 * x, -1},

            {-x, 1},
            {-x, -1}

        };

        int ans = 0;

        vector<pair<int, int>> dir;

        if (ty == 0)
        {

            dir = oneDist;
        }

        else
        {

            dir = twoDist;
        }

        for (auto &pb : dir)
        {

            int new_r = i + pb.first;

            int new_c = j + pb.second;

            if (new_r >= 0 and new_r < n and new_c >= 0 and new_c < m)

                ans += mat[new_r][new_c];
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, ty, i, j;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        cin >> ty >> i >> j;

        Solution ob;
        cout << ob.hopscotch(n, m, mat, ty, i, j) << "\n";
    }
    return 0;
}
// } Driver Code Ends
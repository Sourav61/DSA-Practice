// https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    typedef pair<int, pair<int, int>> pipii;
    int MinimumEffort(vector<vector<int>> &heights)
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

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> heights;

        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < m; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }

        Solution obj;
        cout << obj.MinimumEffort(heights) << "\n";
    }
    return 0;
}
// } Driver Code Ends
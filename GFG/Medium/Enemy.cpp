// https://practice.geeksforgeeks.org/problems/enemy/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int largestArea(int n, int m, int k, vector<vector<int>> &enemy)
    {
        vector<int> rows;

        rows.push_back(-1);

        for (auto &x : enemy)
        {
            rows.push_back(x[0] - 1);
        }

        rows.push_back(n);

        sort(rows.begin(), rows.end());

        int maxRow = 0;
        for (int i = 1; i < rows.size(); i++)
        {
            int prev = rows[i - 1];
            int curr = rows[i];

            maxRow = max(maxRow, curr - prev - 1);
        }

        vector<int> col;

        col.push_back(-1);

        for (auto &x : enemy)
        {
            col.push_back(x[1] - 1);
        }

        col.push_back(m);

        sort(col.begin(), col.end());

        int maxCol = 0;
        for (int i = 1; i < col.size(); i++)
        {
            int prev = col[i - 1];
            int curr = col[i];

            maxCol = max(maxCol, curr - prev - 1);
        }

        return maxRow * maxCol;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int k;
        cin >> k;
        vector<vector<int>> e(k, vector<int>(2));
        for (int i = 0; i < k; i++)
            cin >> e[i][0] >> e[i][1];
        Solution a;
        cout << a.largestArea(n, m, k, e) << endl;
    }
    return 0;
}
// } Driver Code Ends
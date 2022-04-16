// https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1/#

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int>> matrix, int n, int m, int x)
    {
        int r = 0, c = m - 1;

        bool found = false;

        while (r < n && c >= 0)
        {
            if (matrix[r][c] == x)
            {
                return 1;
            }
            else if (matrix[r][c] > x)
            {
                c--;
            }
            else
            {
                r++;
            }
        }

        return 0;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n);

        for (int i = 0; i < n; i++)
        {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.search(matrix, n, m, x))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}

// } Driver Code Ends
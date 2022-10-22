// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        int left = 0, right = c - 1, up = 0, down = r - 1;

        vector<int> res;

        while (res.size() < (r * c))
        {
            for (int j = left; j <= right; j++)
            {
                res.push_back(matrix[up][j]);
            }

            for (int i = up + 1; i <= down; i++)
            {
                res.push_back(matrix[i][right]);
            }

            if (up != down)
            {
                for (int j = right - 1; j >= left; j--)
                {
                    res.push_back(matrix[down][j]);
                }
            }

            if (left != right)
            {
                for (int i = down - 1; i > up; i--)
                {
                    res.push_back(matrix[i][left]);
                }
            }

            left++;
            right--;

            up++;
            down--;
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
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
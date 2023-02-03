// https://practice.geeksforgeeks.org/problems/2e068e2342b9c9f40cfda1ed8e8119542d748fd8/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    pair<int, int> endPoints(vector<vector<int>> matrix)
    {
        int i = 0, j = 0, resI = 0, resJ = 0;
        string curr = "right";
        int n = matrix.size();
        int m = matrix[0].size();

        while (i >= 0 && j >= 0 && i < n && j < m)
        {
            // cout<<i<<" "<<j<<endl;
            resI = i, resJ = j;
            if (curr == "right")
            {
                if (matrix[i][j] == 0)
                {
                    j++;
                }
                else
                {
                    curr = "down";
                    matrix[i][j] = 0;
                }
            }
            else if (curr == "left")
            {
                if (matrix[i][j] == 0)
                {
                    j--;
                }
                else
                {
                    curr = "up";
                    matrix[i][j] = 0;
                }
            }
            else if (curr == "down")
            {
                if (matrix[i][j] == 0)
                {
                    i++;
                }
                else
                {
                    curr = "left";
                    matrix[i][j] = 0;
                }
            }
            else if (curr == "up")
            {
                if (matrix[i][j] == 0)
                {
                    i--;
                }
                else
                {
                    curr = "right";
                    matrix[i][j] = 0;
                }
            }
        }

        return {resI, resJ};
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int row, col;
        scanf("%d", &row);
        scanf("%d", &col);
        vector<vector<int>> matrix(row, vector<int>(col));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        pair<int, int> p = obj.endPoints(matrix);

        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    return 0;
}
// } Driver Code Endss
// https://practice.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
public:
    vector<int> matrixDiagonally(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int rev = 1;

        vector<int> res;
        for (int j = 0; j < m; j++)
        {
            int temp1 = 0;
            int temp2 = j;

            vector<int> temp;

            while (temp1 < n && temp2 >= 0)
            {
                if (rev)
                {
                    temp.push_back(mat[temp1][temp2]);
                }
                else
                {
                    res.push_back(mat[temp1][temp2]);
                }
                temp1++;
                temp2--;
            }

            if (rev)
            {
                reverse(temp.begin(), temp.end());
                for (auto x : temp)
                {
                    res.push_back(x);
                }
            }

            rev = !rev;
        }

        for (int i = 1; i < n; i++)
        {
            int temp1 = i;
            int temp2 = m - 1;

            vector<int> temp;

            while (temp1 < n && temp2 >= 0)
            {
                if (rev)
                {
                    temp.push_back(mat[temp1][temp2]);
                }
                else
                {
                    res.push_back(mat[temp1][temp2]);
                }
                temp1++;
                temp2--;
            }

            if (rev)
            {
                reverse(temp.begin(), temp.end());
                for (auto x : temp)
                {
                    res.push_back(x);
                }
            }

            rev = !rev;
        }

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        int k = 0;
        // cin>>k;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int> ans = obj.matrixDiagonally(mat);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
}
// } Driver Code Ends
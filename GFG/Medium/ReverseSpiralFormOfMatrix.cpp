// https://practice.geeksforgeeks.org/problems/reverse-spiral-form-of-matrix4033/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>> &a)
    {
        int left = 0, right = C - 1, up = 0, down = R - 1;

        vector<int> res;

        while (res.size() < (R * C))
        {
            for (int j = left; j <= right; j++)
            {
                res.push_back(a[up][j]);
            }

            for (int i = up + 1; i <= down; i++)
            {
                res.push_back(a[i][right]);
            }

            if (up != down)
            {
                for (int j = right - 1; j >= left; j--)
                {
                    res.push_back(a[down][j]);
                }
            }

            if (left != right)
            {
                for (int i = down - 1; i > up; i--)
                {
                    res.push_back(a[i][left]);
                }
            }

            left++;
            right--;

            up++;
            down--;
        }

        reverse(res.begin(), res.end());

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
        int R, C;
        cin >> R >> C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for (int i = 0; i < R * C; i++)
            cin >> a[i / C][i % C];
        Solution ob;
        vector<int> ans = ob.reverseSpiral(R, C, a);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
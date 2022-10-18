// https://leetcode.com/problems/diagonal-traverse/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
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

int main()
{

    Solution obj;

    vector<vector<int>> mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<int> res = obj.findDiagonalOrder(mat);

    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
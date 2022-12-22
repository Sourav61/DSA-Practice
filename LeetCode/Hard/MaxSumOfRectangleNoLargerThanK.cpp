// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int R = matrix.size();
        int C = matrix[0].size();

        vector<int> sum(R, 0);
        int maxi = INT_MIN;

        for (int j = 0; j < C; j++)
        {
            fill(sum.begin(), sum.end(), 0);
            for (int col = j; col < C; col++)
            {
                for (int row = 0; row < R; row++)
                {
                    sum[row] += matrix[row][col];
                }
                set<int> s = {0};
                int currSum = 0;
                for (auto &x : sum)
                {
                    currSum += x;
                    auto it = s.lower_bound(currSum - k);
                    if (it != end(s))
                    {
                        maxi = max(maxi, currSum - *it);
                    }
                    s.insert(currSum);
                }
            }
        }

        return maxi;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> matrix = {{5, -4, -3, 4}, {-3, -4, 4, 5}, {5, 1, 5, -4}};

    cout << obj.maxSumSubmatrix(matrix, 8);

    return 0;
}
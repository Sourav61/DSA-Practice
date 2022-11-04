// https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // int n = matrix.size();
        // int m = matrix[0].size();

        // int low,high,mid;

        // for(int i=0;i<n;i++){
        //     if(matrix[i][0] <= target && target <= matrix[i][m-1]){
        //         low = 0, high = m-1;
        //         while(low <= high){
        //             mid = (low + high) / 2;
        //             if(matrix[i][mid] == target){
        //                 return 1;
        //             }else if(matrix[i][mid] > target){
        //                 high = mid-1;
        //             }else{
        //                 low = mid +1;
        //             }
        //         }
        //     }
        // }

        // return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        int r = 0, c = m - 1;

        while (r < n && c >= 0)
        {
            if (matrix[r][c] == target)
            {
                return 1;
            }
            else if (matrix[r][c] > target)
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

int main()
{

    Solution obj;

    vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 10;

    cout << obj.searchMatrix(matrix, target);

    return 0;
}
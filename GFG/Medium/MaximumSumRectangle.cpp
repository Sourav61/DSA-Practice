// https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int kadanes(vector<int> &arr)
    {
        int sz = arr.size();
        int totalSum = INT_MIN, currSum = 0;

        for (int i = 0; i < sz; i++)
        {
            currSum += arr[i];
            if (totalSum < currSum)
            {
                totalSum = currSum;
            }
            if (currSum < 0)
            {
                currSum = 0;
            }
        }

        return totalSum;
    }

    int maximumSumRectangle(int R, int C, vector<vector<int>> M)
    {
        vector<int> sum(R, 0);
        int maxi = INT_MIN;

        for (int j = 0; j < C; j++)
        {
            fill(sum.begin(), sum.end(), 0);
            for (int col = j; col < C; col++)
            {
                for (int row = 0; row < R; row++)
                {
                    sum[row] += M[row][col];
                }
                int currMax = kadanes(sum);
                maxi = max(maxi, currMax);
            }
        }

        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends
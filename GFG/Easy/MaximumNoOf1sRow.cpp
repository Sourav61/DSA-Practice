// https://practice.geeksforgeeks.org/problems/maximum-no-of-1s-row3027/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int binarySearch(vector<int> &v)
    {
        int low = 0;
        int high = v.size() - 1;
        int mid = low + (high - low) / 2;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (v[mid] == 1)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return high;
    }

    int maxOnes(vector<vector<int>> &Mat, int N, int M)
    {
        int maxi = 0, maxIdx = 0, i = 0;

        for (auto &v : Mat)
        {
            int idx = binarySearch(v);
            if (maxi < v.size() - idx)
            {
                maxi = v.size() - idx;
                maxIdx = i;
            }
            i++;
        }

        return maxIdx;
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
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends
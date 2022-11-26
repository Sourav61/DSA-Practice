// https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m)
{

    if (m == 0)
        return true;
    if (n == 0)
        return false;

    if (v1[n - 1] == v2[m - 1])
        return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}

// } Driver Code Ends
/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution
{
public:
    vector<int> find3Numbers(vector<int> arr, int N)
    {
        int x = INT_MAX;
        int y = INT_MIN;

        int left = 0, right = N - 1, xIdx = 0, yIdx = 0;
        while (left <= right)
        {
            if (arr[left] < x)
            {
                xIdx = left;
                x = arr[left];
            }
            if (arr[right] > y)
            {
                yIdx = right;
                y = arr[right];
            }
            if (x < y && y - x > 1)
            {
                for (int i = xIdx + 1; i <= yIdx - 1; i++)
                {
                    if (arr[i] < y && arr[i] > x)
                        return {x, arr[i], y};
                }
            }
            left++;
            right--;
        }
        return {};
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3)
        {
            cout << -1 << "\n";
        }

        if (res.empty())
        {
            cout << 0 << "\n";
        }
        else if ((res[0] < res[1] and res[1] < res[2]) and
                 isSubSequence(a, res, n, res.size()))
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends
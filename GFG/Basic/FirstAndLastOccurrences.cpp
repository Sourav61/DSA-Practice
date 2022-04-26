// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x2041/1/#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int binarySearch(vector<int> &arr, int n, int x, bool flag)
    {
        int l = 0;
        int r = n - 1;
        int result = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
            {
                result = mid;
                if (flag)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else if (arr[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return result;
    }
    vector<int> firstAndLast(vector<int> &arr, int n, int x)
    {
        vector<int> v;
        int left = binarySearch(arr, n, x, true);
        if (left == -1)
        {
            v.push_back(-1);
            return v;
        }
        int right = binarySearch(arr, n, x, false);
        v.push_back(left);
        v.push_back(right);
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans = obj.firstAndLast(arr, n, x);
        for (int i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
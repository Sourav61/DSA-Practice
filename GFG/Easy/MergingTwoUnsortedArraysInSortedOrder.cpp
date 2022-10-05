// https://practice.geeksforgeeks.org/problems/merging-two-unsorted-arrays-in-sorted-order1020/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Your code goes hereclass Solution{

class Solution
{
public:
    void sortedMerge(int a[], int b[], int res[], int n, int m)
    {
        sort(a, a + n);
        sort(b, b + m);

        int k = 0;

        int x = 0;
        int y = 0;

        while (x < n && y < m)
        {
            if (a[x] < b[y])
                res[k++] = a[x++];
            else
                res[k++] = b[y++];
        }

        while (x < n)
        {
            res[k++] = a[x++];
        }

        while (y < m)
        {
            res[k++] = b[y++];
        }
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
        int a[n], b[m];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        int res[n + m];

        Solution ob;
        ob.sortedMerge(a, b, res, n, m);

        for (int i = 0; i < n + m; i++)
        {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
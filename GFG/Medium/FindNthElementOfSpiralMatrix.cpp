// https://practice.geeksforgeeks.org/problems/find-nth-element-of-spiral-matrix/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int findK(int[MAX][MAX], int, int, int);
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        int k = 0;
        // cin>>k;
        cin >> n >> m >> k;
        int a[MAX][MAX];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        cout << findK(a, n, m, k) << endl;
    }
}
// } Driver Code Ends

/*You are required to complete this method*/
int findK(int A[MAX][MAX], int n, int m, int k)
{
    vector<int> res;

    int left = 0, right = m - 1, up = 0, down = n - 1;

    int ele = 1;

    while (res.size() < (n * m))
    {
        for (int j = left; j <= right; j++)
        {
            res.push_back(A[up][j]);
        }

        for (int i = up + 1; i <= down; i++)
        {
            res.push_back(A[i][right]);
        }

        if (up != down)
        {
            for (int j = right - 1; j >= left; j--)
            {
                res.push_back(A[down][j]);
            }
        }

        if (left != right)
        {
            for (int i = down - 1; i > up; i--)
            {
                res.push_back(A[i][left]);
            }
        }

        left++;
        right--;

        up++;
        down--;
    }

    return res[k - 1];
}

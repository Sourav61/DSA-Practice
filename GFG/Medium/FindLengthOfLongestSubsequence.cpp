// https://practice.geeksforgeeks.org/problems/find-length-of-longest-subsequence4905/1

//{ Driver Code Starts
#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int maxSubsequenceSubstring(string x, string y, int n, int m);

// Driver Program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        string x, y;
        cin >> n >> m;
        cin >> x >> y;
        cout << maxSubsequenceSubstring(x, y, n, m) << "\n";
    }
    return 0;
}
// } Driver Code Ends

int maxSubsequenceSubstring(string x, string y, int n, int m)
{
    int maxi = 0;

    for (int i = 0; i < m; i++)
    {
        int k = i;
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            while (k < m && x[j] == y[k])
            {
                k++;
                j++;
                temp++;
            }
        }

        maxi = max(temp, maxi);
    }

    return maxi;
}
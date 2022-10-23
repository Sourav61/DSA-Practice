// https://practice.geeksforgeeks.org/problems/stepping-numberswrong-output1813/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(int &count, int n, int m, int start)
    {
        if (start > m)
            return;

        if (start <= m && start >= n)
            count++;

        int rem = start % 10;

        if (rem != 9)
            dfs(count, n, m, start * 10 + (rem + 1));

        if (rem != 0)
            dfs(count, n, m, start * 10 + (rem - 1));

        return;
    }

    int steppingNumbers(int n, int m)
    {
        int count = 0;
        if (n == 0)
            count++;
        for (int i = 1; i <= 9; i++)
        {
            dfs(count, n, m, i);
        }

        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << obj.steppingNumbers(n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
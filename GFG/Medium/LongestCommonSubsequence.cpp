// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings.
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == t[j])
        {
            return dp[i][j] = 1 + f(i - 1, j - 1, s, t, dp);
        }

        return dp[i][j] = max(f(i - 1, j, s, t, dp), f(i, j - 1, s, t, dp));
    }

    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x, vector<int>(y, -1));

        return f(x - 1, y - 1, s1, s2, dp);
    }

    // int lcs(int x, int y, string s1, string s2)
    // {
    //     vector<int> prev(y+1,0),cur(y+1,0);

    //     for(int j=0;j<=y;j++){
    //         prev[j] = 0;
    //     }

    //     for(int i=1;i<=x;i++){
    //         for(int j=1;j<=y;j++){
    //             if(s1[i-1] == s2[j-1]){
    //                 cur[j] = 1 + prev[j-1];
    //             }else{
    //                 cur[j] = max(prev[j],cur[j-1]);
    //             }
    //         }
    //         prev = cur;
    //     }

    //     return prev[y];
    // }
};

//{ Driver Code Starts.
int main()
{
    int t, n, k, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends
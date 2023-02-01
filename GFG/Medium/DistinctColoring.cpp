// https://practice.geeksforgeeks.org/problems/844b4fdcd988ac5461324d62d43f7892749a113c/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // long long int f(int ind,int N,int r[],int g[],int b[],int prev,vector<vector<long long int>>& dp)
    // {
    //     if(ind==N) return 0;

    //     if(dp[ind][prev]!=-1) return dp[ind][prev];

    //     long long int taker=1e11,takeg=1e11,takeb=1e11;
    //     if(prev==0)
    //     {
    //         taker=r[ind]+f(ind+1,N,r,g,b,1,dp);
    //         takeg=g[ind]+f(ind+1,N,r,g,b,2,dp);
    //         takeb=b[ind]+f(ind+1,N,r,g,b,3,dp);
    //     }
    //     else if(prev==1)
    //     {
    //         takeg=g[ind]+f(ind+1,N,r,g,b,2,dp);
    //         takeb=b[ind]+f(ind+1,N,r,g,b,3,dp);
    //     }
    //     else if(prev==2)
    //     {
    //         taker=r[ind]+f(ind+1,N,r,g,b,1,dp);
    //         takeb=b[ind]+f(ind+1,N,r,g,b,3,dp);
    //     }
    //     else
    //     {
    //         takeg=r[ind]+f(ind+1,N,r,g,b,1,dp);
    //         takeb=g[ind]+f(ind+1,N,r,g,b,2,dp);
    //     }
    //     return dp[ind][prev]=min(taker,min(takeb,takeg));
    // }
    // long long int distinctColoring(int N, int r[], int g[], int b[]){
    //     vector<vector<long long int>>  dp(N,vector<long long int>(4,-1));
    //     return f(0,N,r,g,b,0,dp);
    // }

    long long int sol(int prev, int idx, int &n, int r[], int g[], int b[], vector<vector<long long int>> &dp)
    {
        if (idx == n)
        {
            return 0;
        }

        long long int take1 = INT_MAX;
        long long int take2 = INT_MAX;

        if (dp[idx][prev] != -1)
        {
            return dp[idx][prev];
        }

        // cout<<prev<<" "<<idx<<endl;
        if (prev == 0)
        {
            take1 = g[idx] + sol(1, idx + 1, n, r, g, b, dp);
            take2 = b[idx] + sol(2, idx + 1, n, r, g, b, dp);
        }

        if (prev == 1)
        {
            take1 = r[idx] + sol(0, idx + 1, n, r, g, b, dp);
            take2 = b[idx] + sol(2, idx + 1, n, r, g, b, dp);
        }
        if (prev == 2)
        {
            take1 = g[idx] + sol(1, idx + 1, n, r, g, b, dp);
            take2 = r[idx] + sol(0, idx + 1, n, r, g, b, dp);
        }
        return dp[idx][prev] = min(take1, take2);
    }

    long long int distinctColoring(int N, int r[], int g[], int b[])
    {
        long long int mini = INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            vector<vector<long long int>> dp(N + 1, vector<long long int>(3, -1));
            mini = min(mini, sol(i, 0, N, r, g, b, dp));
        }
        return mini;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int r[N], g[N], b[N];
        for (int i = 0; i < N; i++)
            cin >> r[i];
        for (int i = 0; i < N; i++)
            cin >> g[i];
        for (int i = 0; i < N; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0;
}
// } Driver Code Ends
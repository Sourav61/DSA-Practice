// https://practice.geeksforgeeks.org/problems/black-and-white-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main()
{
    // code
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Function to find out the number of ways we can place a black and a
// white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m)
{
    // int dx[] = {2,2,1,1,-1,-1,-2,-2};
    // int dy[] = {-1,1,-2,2,-2,2,-1,1};

    // long long mod = 1e9 + 7;
    // long long attack = 0;

    // long long total = ((n*m)%mod * (m*n-1)%mod) % mod;

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         for(int k=0;k<8;k++){
    //             int nrow = i + dx[k];
    //             int ncol = j + dy[k];

    //             if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
    //                 attack++;
    //             }
    //         }
    //     }
    // }

    // return ((total)%mod - (attack)%mod)%mod;

    int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    long long mod = 1e9 + 7;
    long long attack = 0;

    long long total = ((n * m) % mod * (m * n - 1) % mod) % mod;

    if (n >= 1 && m >= 2)
    {
        total -= 4 * (n - 1) * (m - 2);
    }
    if (m >= 1 && n >= 2)
    {
        total -= 4 * (m - 1) * (n - 2);
    }

    return total;
}
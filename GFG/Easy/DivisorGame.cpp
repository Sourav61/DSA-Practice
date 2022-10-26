// https://practice.geeksforgeeks.org/problems/divisor-game-1664432414/1?page=1&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=accuracy

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // bool f(int x,int n,vector<int> &dp){
    //     if(n < 1){
    //         return false;
    //     }
    //     if(n == 1){
    //         if(x % 2 != 0){
    //             return true;
    //         }else{
    //             return false;
    //         }
    //     }

    //     if(dp[n] != -1){
    //         return dp[n];
    //     }

    //     for(int i=1;i*i<=n;i++){
    //         if(x % i == 0){
    //             return dp[n] = f(x+1,n-i,dp);
    //         }
    //     }

    //     return dp[n] = false;
    // }

    // bool divisorGame(int n) {
    //     vector<int> dp(n+1,-1);
    //     return f(0,n,dp);
    // }

    bool divisorGame(int N)
    {
        if (N % 2 == 0)
        {
            return true;
        }
        return false;
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

        Solution obj;
        bool ans = obj.divisorGame(N);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
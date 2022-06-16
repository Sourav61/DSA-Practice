// https://practice.geeksforgeeks.org/contest/interview-series-53/problems/#

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dis(int i,int j,int mice[],int cheese[]){
        return abs(mice[j] - cheese[i]);
    }

    int minTimeToEat(int N, int M, int mice[], int cheese[]) {
        int dp[M][N], dp2[M][N];
        int MAX = 1000000000;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                dp[i][j] = dp2[i][j] =  MAX;
            }
        }

        sort(mice,mice+N);
        sort(cheese, cheese+M);

        dp[0][0] = dp2[0][0] = dis(0,0,mice,cheese);

        for(int j=1;j<N;j++){
            dp[0][j] = dis(0,j,mice,cheese);
            dp2[0][j] = min(dp[0][j],dp2[0][j-1]);
    }   

        for(int i=1;i<M;i++){
            for(int j=1;j<N;j++){
                dp[i][j] = max(dis(i,j,mice,cheese), dp2[i-1][j-1]);
                dp2[i][j] = min(dp[i][j], dp2[i][j-1]);
            }
        }

        return dp2[M-1][N-1];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;

        cin >> N >> M;
        int mice[N], cheese[M];
        for (int i = 0; i < N; i++) {
            cin >> mice[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> cheese[i];
        }
        Solution ob;
        cout << ob.minTimeToEat(N, M, mice, cheese) << endl;
    }
}  // } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int kthLargest(vector<int> &Arr, int N, int K)
    {
        // priority_queue<int, vector<int>> maxH;

        // vector<int> dp(N + 1, 0);

        // for (int i = 0; i < N; i++)
        // {
        //     int sum = 0;
        //     for (int j = 0; j <= i; j++)
        //     {
        //         sum += Arr[j];
        //         // cout<<Arr[i]<<" "<<Arr[j]<<endl;
        //     }
        //     // cout<<endl<<endl;
        //     dp[i] = sum;
        // }

        // maxH.push(dp[0]);

        // for (int i = 1; i < N; i++)
        // {
        //     maxH.push(dp[i]);
        //     for (int j = i; j < N; j++)
        //     {
        //         maxH.push(dp[j] - dp[i - 1]);
        //     }
        //     // cout<<endl;
        // }

        // while (--K)
        // {
        //     maxH.pop();
        // }

        // return maxH.top();


        priority_queue<int,vector<int>> maxH;
        
        vector<int> dp(N+1,0);
        
        for(int i=0;i<N;i++){
            int sum = 0;
            for(int j=i;j<N;j++){
                sum += Arr[j];
                maxH.push(sum);
            }
        }
        
        while(--K){
            maxH.pop();
        }
        
        return maxH.top();
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N;
        cin >> K;
        vector<int> Arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> Arr[i];
        }
        Solution ob;
        int ans = ob.kthLargest(Arr, N, K);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
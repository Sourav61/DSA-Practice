// https://practice.geeksforgeeks.org/problems/grouping-of-numbers0015/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxGroupSize(int arr[], int N, int K)
    {
        vector<int> rems(K, 0);
        for (int i = 0; i < N; i++)
        {
            rems[arr[i] % K]++;
        }

        int i = 1, j = K - 1;
        int cnt = rems[0] ? 1 : 0;

        while (i < j)
        {
            cnt += max(rems[i], rems[j]);
            i++;
            j--;
        }

        return cnt + (i == j && rems[j]);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;

        cin >> N >> K;
        int arr[N];

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr, N, K) << endl;
    }
    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int K)
    {
        if (N == 0)
        {
            return 0;
        }

        unordered_map<int, int> mp;

        int currSum = 0, i = 0, maxLen = 0;

        while (i < N)
        {
            currSum += A[i];

            if (mp.find(currSum) == mp.end())
            {
                mp[currSum] = i;
            }

            if (currSum == K)
            {
                maxLen = max(i + 1, maxLen);
            }

            if (mp.find(currSum - K) != mp.end())
            {
                maxLen = max(i - mp[currSum - K], maxLen);
            }

            i++;
        }

        return maxLen;
    }
};

//{ Driver Code Starts.

int main()
{
    // code

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.lenOfLongSubarr(a, n, k) << endl;
    }

    return 0;
}
// } Driver Code Ends
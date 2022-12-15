// https://practice.geeksforgeeks.org/problems/f04fd67b26b4828b6180715d8b1700426b637247/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isPossible(int maxSum, int arr[], int k, int n)
    {
        int cnt = 0;
        int currSum = 0;

        for (int i = 0; i < n; i++)
        {
            if (currSum + arr[i] > maxSum)
            {
                currSum = arr[i];
                cnt++;
            }
            else
            {
                currSum += arr[i];
            }
        }

        if (currSum <= maxSum)
        {
            cnt++;
        }

        return cnt <= k;
    }

    int splitArray(int arr[], int N, int K)
    {
        int low = 0;
        int high = 0;
        int ans = 0;

        for (int i = 0; i < N; i++)
        {
            low = max(low, arr[i]);
            high += arr[i];
        }

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (isPossible(mid, arr, K, N))
            {
                high = mid - 1;
                ans = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
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
        cout << ob.splitArray(arr, N, K);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int leastWeightCapacity(int arr[], int N, int D)
    {
        int left = 0, right = 0;
        for (int i = 0; i < N; i++)
        {
            left = max(left, arr[i]);
            right += arr[i];
        }

        while (left < right)
        {
            int mid = (left + right) / 2;
            int need = 1, curr = 0;

            for (int i = 0; i < N && need <= D; i++)
            {
                curr += arr[i];
                if (curr > mid)
                {
                    curr = arr[i];
                    need++;
                }
            }

            if (need > D)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    }
    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        if (arr[0] == 0 && n > 1)
            return -1;

        if (n == 1)
            return 0;

        int steps = arr[0];
        int maxReach = arr[0];
        int jumps = 1;

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
                return jumps;

            if (steps)
            {
                maxReach = max(maxReach, arr[i] + i);
                steps--;
            }

            if (steps == 0)
            {
                if (i >= maxReach)
                    return -1;
                jumps++;
                steps = maxReach - i;
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
        // for(int i=0; i<n; i++)
        //     cin>>arr[i];
        Solution obj;

        cout << obj.minJumps(arr, 11) << endl;
    }
    return 0;
}

// } Driver Code Ends
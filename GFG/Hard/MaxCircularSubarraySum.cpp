// https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1/#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // num: size of array
    // Function to find maximum circular subarray sum.
    int kadane(int A[], int n)
    {
        int currentSum = INT_MIN;
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            currentSum = max(currentSum + A[i], A[i]);
            maxSum = max(currentSum, maxSum);
        }
        return maxSum;
    }

    int circularSubarraySum(int arr[], int num)
    {

        // your code here

        if (num == 1)
        {
            return arr[0];
        }
        if (num == 2)
        {
            int num = arr[0] + arr[1];
            int num2 = max(arr[0], arr[1]);
            return max(num, num2);
        }

        int wrapsum = INT_MIN;
        int nowrapsum = INT_MIN;

        nowrapsum = kadane(arr, num);
        int total = 0;

        for (int i = 0; i < num; i++)
        {
            total += arr[i];
            arr[i] = -arr[i];
        }

        wrapsum = total + kadane(arr, num);

        return max(wrapsum, nowrapsum);
    }
};

// { Driver Code Starts.

int main()
{
    int T;

    // testcases
    cin >> T;

    while (T--)
    {
        int num;

        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];

        Solution ob;
        // calling function
        cout << ob.circularSubarraySum(arr, num) << endl;
    }

    return 0;
} // } Driver Code Ends
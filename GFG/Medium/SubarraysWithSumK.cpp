// https://practice.geeksforgeeks.org/problems/subarrays-with-sum-k/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int findSubArraySum(int Arr[], int n, int k)
    {
        if (n == 0)
        {
            return 0;
        }

        unordered_map<int, int> mp;

        int currSum = 0, i = 0, count = 0;

        while (i < n)
        {
            currSum += Arr[i];

            if (currSum == k)
            {
                count += 1;
            }

            if (mp.find(currSum - k) != mp.end())
            {
                count += mp[currSum - k];
            }

            mp[currSum] += 1;
            i++;
        }

        return count;
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
        int Arr[N];
        for (int i = 0; i < N; i++)
            cin >> Arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.findSubArraySum(Arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends
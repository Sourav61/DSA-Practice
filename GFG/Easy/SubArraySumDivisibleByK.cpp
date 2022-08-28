// https://practice.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k2617/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    long long subCount(long long arr[], int N, long long K)
    {
        unordered_map<int, int> mp;

        mp[0] = 1;

        long long int sum = 0, count = 0;

        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
            sum = sum % K;
            if (sum < 0)
            {
                sum += K;
            }

            if (mp.find(sum) != mp.end())
            {
                count += mp[sum];
                mp[sum]++;
            }
            else
            {
                mp[sum] = 1;
            }
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
        int n;
        long long k;
        cin >> n >> k;
        long long a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        Solution ob;
        cout << ob.subCount(a, n, k);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
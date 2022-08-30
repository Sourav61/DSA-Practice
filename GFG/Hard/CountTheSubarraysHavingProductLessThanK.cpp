// https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {
        int count = 0, start = 0, end = 0;
        unsigned long long mult = 1;
        while (end < n && start < n)
        {
            mult *= a[end];

            while (mult >= k && start < end)
            {
                mult /= a[start++];
            }

            if (mult < k)
                count += (end - start + 1);

            end++;
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
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
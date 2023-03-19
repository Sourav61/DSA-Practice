// https://practice.geeksforgeeks.org/problems/number-of-subarrays-with-maximum-values-in-given-range5949/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long countSubarrays(int nums[], int n, int L, int R)
    {
        int st = 0, end = 0, res = 0, prev = 0;

        while (end < n)
        {
            if (nums[end] >= L && nums[end] <= R)
            {
                prev = end - st + 1;
                res += prev;
            }
            else if (nums[end] < L)
            {
                res += prev;
            }
            else
            {
                st = end + 1;
                prev = 0;
            }
            end++;
        }

        return res;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, l, r;
        cin >> n >> l >> r;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.countSubarrays(a, n, l, r) << endl;
    }
    return 0;
}

// } Driver Code Ends
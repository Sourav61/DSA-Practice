// https://practice.geeksforgeeks.org/problems/koko-eating-bananas/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int Solve(int N, vector<int> &piles, int H)
    {
        int maxi = INT_MIN;
        for (auto &x : piles)
        {
            maxi = max(maxi, x);
        }
        if (H == piles.size())
            return maxi;

        int low = 1, high = maxi;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long int tim = 0;

            for (auto &x : piles)
            {
                tim += (long long int)(ceil(x * 1.0 / mid));
            }

            if (tim <= H)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
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
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
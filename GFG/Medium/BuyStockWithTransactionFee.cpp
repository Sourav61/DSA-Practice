// https://practice.geeksforgeeks.org/problems/buy-stock-with-transaction-fee/1?page=1&sortBy=accuracy&query=page1sortByaccuracy

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long maximumProfit(vector<long long> &prices, int n, int fee)
    {
        vector<long long> curr(2, 0);
        vector<long long> front(2, 0);
        long long profit = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            curr[1] = max(-prices[ind] + front[0], 0 + front[1]);
            curr[0] = max(prices[ind] - fee + front[1], 0 + front[0]);

            front = curr;
        }

        return curr[1];
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
        vector<long long> prices;

        for (int i = 0; i < n; ++i)
        {
            long long x;
            cin >> x;
            prices.push_back(x);
        }

        int fee;
        cin >> fee;

        Solution obj;
        cout << obj.maximumProfit(prices, n, fee) << "\n";
    }
    return 0;
}
// } Driver Code Ends
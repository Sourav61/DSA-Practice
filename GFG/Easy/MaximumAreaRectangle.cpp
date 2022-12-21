// https://practice.geeksforgeeks.org/problems/maximum-area-rectangle/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int calculate_Area(vector<pair<int, int>> &rect, int N)
    {
        int maxi = INT_MIN;

        for (int i = 0; i < N; i++)
        {
            maxi = max(maxi, rect[i].first * rect[i].second);
        }

        return maxi;
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
        vector<pair<int, int>> rect;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            rect.push_back({a, b});
        }
        Solution ob;
        cout << ob.calculate_Area(rect, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
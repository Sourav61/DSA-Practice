// https://practice.geeksforgeeks.org/problems/minimum-distinct-ids3251/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int distinctIds(int arr[], int n, int m)
    {
        priority_queue<long long int, vector<long long int>, greater<long long int>> minH;
        map<long long int, long long int> mp;

        if (m > n)
        {
            return 0;
        }

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        for (auto x : mp)
        {
            minH.push(x.second);
        }

        while (m > 0)
        {
            int num = minH.top();

            m -= num;
            if (m >= 0)
            {
                minH.pop();
            }
        }

        return !minH.empty() ? minH.size() : 0;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int m;
        cin >> m;
        Solution ob;
        cout << ob.distinctIds(arr, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends
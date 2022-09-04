// https://practice.geeksforgeeks.org/problems/top-k-numbers3425/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    static bool com(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second > b.second;
    }

    vector<int> kTop(int a[], int n, int k)
    {
        // code here.
        vector<int> v;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[a[i]]++;
            vector<pair<int, int>> ans;
            for (auto x : mp)
            {
                ans.push_back({x.first, x.second});
            }
            sort(ans.begin(), ans.end(), com);
            if (ans.size() < k)
            {
                for (int i = 0; i < ans.size(); i++)
                {
                    v.push_back(ans[i].first);
                }
            }
            else
            {
                for (int i = 0; i < k; i++)
                {
                    v.push_back(ans[i].first);
                }
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;

    cin >> t;

    while (t--)
    {
        long long n;
        long long k;
        cin >> n;
        cin >> k;
        int a[n];
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<int> ans;
        ans = ob.kTop(a, n, k);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
            cout << " ";
        }
        cout << '\n';
    }
    return 0;
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/k-closest-elements3619/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x)
    {
        priority_queue<pair<int, int>> pq;
        vector<int> v;
        int i;
        for (i = 0; i < n; i++)
        {
            if (x - arr[i] != 0)
            {
                pq.push({abs(x - arr[i]), arr[i]});
                if (pq.size() > k + 1)
                {
                    pq.pop();
                }
            }
        }
        while (!pq.empty())
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        reverse(v.begin(), v.end());
        for (i = 0; i < v.size() - 1; i++)
        {
            if (abs(x - v[i]) == abs(x - v[i + 1]))
            {
                if (v[i] < v[i + 1])
                {
                    swap(v[i], v[i + 1]);
                }
            }
        }
        if (v.size() != k)
        {
            v.pop_back();
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
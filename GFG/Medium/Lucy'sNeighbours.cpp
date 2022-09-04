// https://practice.geeksforgeeks.org/problems/20b8ec4db3f8da0697acdd3d54d9af9f76405443/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> Kclosest(vector<int> arr, int n, int x, int k)
    {
        priority_queue<pair<int, int>> maxH;

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {

            maxH.push({abs(x - arr[i]), arr[i]});
            if (maxH.size() > k)
            {
                maxH.pop();
            }
        }
        while (!maxH.empty())
        {
            ans.push_back(maxH.top().second);
            maxH.pop();
        }

        sort(ans.begin(), ans.end());

        for (int i = 0; i < ans.size() - 1; i++)
        {
            if (abs(x - ans[i]) == abs(x - ans[i + 1]))
            {
                if (ans[i] > ans[i + 1])
                {
                    swap(ans[i], ans[i + 1]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, k;
        cin >> n >> x >> k;
        vector<int> array(n);
        for (int i = 0; i < n; ++i)
            cin >> array[i];

        Solution obj;
        vector<int> result = obj.Kclosest(array, n, x, k);
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return the sorted array.
    vector<int> nearlySorted(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minH;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            minH.push(arr[i]);
            if (minH.size() > k)
            {
                ans.push_back(minH.top());
                minH.pop();
            }
        }

        while (!minH.empty())
        {
            ans.push_back(minH.top());
            minH.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int num, K;
        cin >> num >> K;

        int arr[num];
        for (int i = 0; i < num; ++i)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res = ob.nearlySorted(arr, num, K);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";

        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
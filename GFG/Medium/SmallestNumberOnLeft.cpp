// https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> leftSmaller(int n, int arr[])
    {
        int i = 0;

        vector<int> res;
        // res.push_back(-1);

        stack<int> st;

        while (i < n)
        {
            while (!st.empty() && arr[i] <= st.top())
            {
                st.pop();
            }
            if (!st.empty())
            {
                res.push_back(st.top());
            }
            else
            {
                res.push_back(-1);
            }
            st.push(arr[i]);
            i++;
        }

        // reverse(res.begin(), res.end());

        return res;
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
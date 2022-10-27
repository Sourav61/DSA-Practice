// https://practice.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> leafNodes(int arr[], int N)
    {
        stack<int> st;
        vector<int> res;
        for (int i = 0; i < N; i++)
        {
            int cnt = 0, last = -1;

            while (!st.empty() && st.top() < arr[i])
            {
                if (last == -1)
                {
                    last = st.top();
                }
                st.pop();
                cnt++;
            }

            if (cnt >= 2)
            {
                res.push_back(last);
            }

            st.push(arr[i]);
        }

        res.push_back(st.top());
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
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> ans = ob.leafNodes(arr, N);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> res;
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top().second <= price[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                st.push({i, price[i]});
                res.push_back(i + 1);
                continue;
            }

            int idx = st.top().first;
            st.push({i, price[i]});
            res.push_back(i - idx);
        }

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
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
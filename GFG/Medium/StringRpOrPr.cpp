// https://practice.geeksforgeeks.org/problems/d25f415de2ff3e02134de03e17ad019d723ab2e9/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long solve(int X, int Y, string S)
    {
        stack<char> st;
        long long res = 0;

        string s1 = "pr", s2 = "rp";

        if (X < Y)
        {
            s1 = "rp", s2 = "pr";
            swap(X, Y);
        }

        for (auto &x : S)
        {
            if (!st.empty() && st.top() == s1[0] && x == s1[1])
            {
                st.pop();
                res += X;
            }
            else
                st.push(x);
        }

        S = "";
        while (!st.empty())
        {
            S.push_back(st.top());
            st.pop();
        }

        reverse(S.begin(), S.end());
        // cout<<S<<endl;

        for (auto &x : S)
        {
            if (!st.empty() && st.top() == s2[0] && x == s2[1])
            {
                st.pop();
                res += Y;
            }
            else
                st.push(x);
        }

        return res;
    }
};

//{ Driver Code Starts.
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int X, Y;
        cin >> X >> Y;
        string S;
        cin >> S;
        Solution obj;
        long long answer = obj.solve(X, Y, S);
        cout << answer << endl;
    }
}
// } Driver Code Ends
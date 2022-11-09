// https://practice.geeksforgeeks.org/problems/remove-k-digits/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string removeKdigits(string S, int K)
    {
        stack<char> st;
        string res;
        int n = S.length();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && K > 0 && st.top() > S[i])
            {
                st.pop();
                K--;
            }

            if (!st.empty() || S[i] != '0')
            {
                st.push(S[i]);
            }
        }

        while (!st.empty() && K--)
        {
            st.pop();
        }

        if (st.empty())
        {
            return "0";
        }

        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

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
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends
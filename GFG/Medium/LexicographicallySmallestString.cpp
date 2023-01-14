// https://practice.geeksforgeeks.org/problems/mila-and-strings0435/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    bool isPow(int n)
    {
        int cnt = 0;
        while (n > 0)
        {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt > 1 ? false : true;
    }

    string lexicographicallySmallest(string S, int k)
    {
        stack<char> st;
        int n = S.length();
        if (isPow(n))
        {
            k /= 2;
        }
        else
        {
            k *= 2;
        }

        if (k >= n)
        {
            return "-1";
        }

        string res = "";

        int i = 0;
        while (i < n)
        {
            while (!st.empty() && st.top() > S[i] && k > 0)
            {
                st.pop();
                k--;
            }
            st.push(S[i]);
            i++;
        }

        while (k)
        {
            st.pop();
            k--;
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
        int k;
        cin >> S >> k;
        Solution ob;
        cout << ob.lexicographicallySmallest(S, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
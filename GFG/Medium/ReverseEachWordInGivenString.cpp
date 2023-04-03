// https://practice.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string1001/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        int n = s.length();

        string temp = "";

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '.')
            {
                st.push(temp);
                temp = "";
            }
            else
                temp += s[i];
        }

        if (temp != "")
        {
            st.push(temp);
        }

        string res = "";

        if (s[0] == '.')
        {
            res += '.';
        }

        while (!st.empty())
        {
            res += st.top();
            if (st.size() > 1)
                res += ".";
            st.pop();
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.reverseWords(s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
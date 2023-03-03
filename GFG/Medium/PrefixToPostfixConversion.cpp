

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string preToPost(string str)
    {
        stack<string> st;

        reverse(str.begin(), str.end());
        int i = 0;
        while (i < str.size())
        {
            char ch = str[i];
            if (!st.empty() && (ch == '+' || ch == '-' || ch == '*' || ch == '/'))
            {
                string a = st.top();
                st.pop();

                string b = st.top();
                st.pop();

                st.push(a + b + ch);
            }
            else
            {
                string curr(1, str[i]);
                st.push(curr);
            }
            i++;
        }

        return st.top();
    }
};

//{ Driver Code Starts.

int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
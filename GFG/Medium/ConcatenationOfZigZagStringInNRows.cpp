// https://practice.geeksforgeeks.org/problems/concatenation-of-zig-zag-string-in-n-rows0308/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        string res = "";
        int increment = 0;

        for (int r = 0; r < numRows; r++)
        {
            increment = 2 * (numRows - 1);
            for (int i = r; i < s.size(); i += increment)
            {
                res += s[i];
                if (r > 0 && r < numRows - 1 &&
                    i + increment - 2 * r < s.size())
                {
                    res += s[i + increment - 2 * r];
                }
            }
        }

        return res;
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int n;
        cin >> n;
        Solution ob;
        cout << ob.convert(str, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
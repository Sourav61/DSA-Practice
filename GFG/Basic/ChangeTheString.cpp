// https://practice.geeksforgeeks.org/problems/change-the-string3541/1#

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string modify(string s)
    {
        if (s[0] >= 'a' && s[0] <= 'z')
            transform(s.begin(), s.end(), s.begin(), ::tolower);
        else
            transform(s.begin(), s.end(), s.begin(), ::toupper);

        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.modify(s) << endl;
    }
} // } Driver Code Ends
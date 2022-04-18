// https://practice.geeksforgeeks.org/problems/encrypt-the-string-10337/1/#

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string encryptString(string s)
    {
        // code here
        string res = "";
        int n = s.length();
        for (int i = 0; i < n;)
        {
            char ch = s[i];
            if (s[i] == s[i + 1])
            {
                res += ch;
                int count = 1;
                int j = i + 1;
                while (j < n and s[i] == s[j])
                {
                    j++;
                    count++;
                }
                i = j;
                res += to_string(count);
            }
            else
            {
                res += ch;
                res += to_string(1);
                i++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
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
        string ans = ob.encryptString(s);
        cout << ans << endl;
    }
}
// } Driver Code Ends
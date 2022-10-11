// https://practice.geeksforgeeks.org/problems/decode-the-string2444/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string decodedString(string s)
    {
        stack<int> cnt;
        stack<string> ans;
        int n = s.length();

        string res = "";

        int i = 0;

        while (i < n)
        {
            if (isdigit(s[i]))
            {
                int count = 0;
                while (isdigit(s[i]))
                {
                    count = count * 10 + (s[i] - '0');
                    i++;
                }
                cnt.push(count);
            }
            else if (s[i] == '[')
            {
                ans.push(res);
                res = "";
                i++;
            }
            else if (s[i] == ']')
            {
                string temp = ans.top();
                ans.pop();
                int count = cnt.top();
                cnt.pop();

                for (int i = 0; i < count; i++)
                {
                    temp.append(res);
                }

                res = temp;
                i++;
            }
            else
            {
                res += s[i];
                i++;
            }
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
        cout << ob.decodedString(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends
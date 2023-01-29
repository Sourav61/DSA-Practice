// https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
public:
    bool isValid(string str)
    {
        if (str[0] == '0')
        {
            return false;
        }

        return (int)stoi(str) <= 255;
    }

    void helper(string &s, int &n, int i, int parts, string ans, vector<string> &res)
    {
        if (parts == 4 || i == n)
        {
            if (i == n && parts == 4)
            {
                res.push_back(ans.substr(0, ans.length() - 1));
            }
            return;
        }

        helper(s, n, i + 1, parts + 1, ans + s[i] + ".", res);

        if (i + 2 <= n && isValid(s.substr(i, 2)))
        {
            helper(s, n, i + 2, parts + 1, ans + s.substr(i, 2) + ".", res);
        }
        if (i + 3 <= n && isValid(s.substr(i, 3)))
        {
            helper(s, n, i + 3, parts + 1, ans + s.substr(i, 3) + ".", res);
        }
    }

    vector<string> genIp(string &s)
    {
        vector<string> res;
        int n = s.length();
        helper(s, n, 0, 0, "", res);

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if (str.size() == 0)
            cout << -1 << "\n";
        else
        {
            for (auto &u : str)
            {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends
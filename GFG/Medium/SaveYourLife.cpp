// https://practice.geeksforgeeks.org/problems/save-your-life4601/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string maxSum(string w, char x[], int b[], int n)
    {
        unordered_map<char, int> mp;

        int len = w.length();

        for (int i = 0; i < len; i++)
        {
            mp[w[i]] = w[i];
        }

        for (int i = 0; i < n; i++)
        {
            mp[x[i]] = b[i];
        }

        string ans = "", res;
        int sum = 0, max = INT_MIN;

        for (int i = 0; i < len; i++)
        {
            sum += mp[w[i]];
            ans += w[i];

            if (sum > max)
            {
                res = ans;
                max = sum;
            }
            if (sum < 0)
            {
                sum = 0;
                ans = "";
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
        string w;
        cin >> w;
        int n;
        cin >> n;
        char x[n];
        int b[n];
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.maxSum(w, x, b, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
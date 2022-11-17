// https://practice.geeksforgeeks.org/problems/sum-of-beauty-of-all-substrings-1662962118/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int beautySum(string s)
    {
        int res = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            vector<int> mp(26, 0);
            for (int j = i; j < n; j++)
            {
                mp[s[j] - 'a']++;
                int maxi = 0, mini = 1e9;
                if (mp.size() == 1)
                {
                    continue;
                }
                for (auto &x : mp)
                {
                    maxi = max(x, maxi);
                    if (x >= 1)
                    {
                        mini = min(x, mini);
                    }
                }

                if (maxi != mini && mini != 1e9)
                {
                    res += maxi - mini;
                }
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
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends
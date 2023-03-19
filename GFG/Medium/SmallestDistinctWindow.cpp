// https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findSubString(string s)
    {
        set<char> s1;

        for (auto &x : s)
        {
            s1.insert(x);
        }

        unordered_map<char, int> mp;

        int j = 0, minLen = INT_MAX;

        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;

            while (j <= i && mp.size() == s1.size())
            {
                minLen = min(minLen, i - j + 1);
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    mp.erase(s[j]);

                j++;
            }
        }

        return minLen;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends

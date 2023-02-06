// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int search(string pat, string txt)
    {
        unordered_map<char, int> mp;
        int res = 0;
        if (pat.size() > txt.size())
        {
            return res;
        }
        int k = pat.length();
        for (auto &x : pat)
        {
            mp[x]++;
        }

        for (int i = 0; i < txt.size(); i++)
        {
            if (i >= pat.size())
            {
                mp[txt[i - pat.size()]]++;
            }
            mp[txt[i]]--;

            int flag = 0;
            for (auto &x : mp)
            {
                if (x.second != 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                res++;
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
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
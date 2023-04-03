// https://practice.geeksforgeeks.org/problems/string-subsequence-game5515/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    unordered_map<char, int> mp;
    set<string> res;

    void sol(int i, string temp, int &n, string &S)
    {
        if (i == n)
        {
            if (temp.size() > 1 && mp[temp[temp.size() - 1]] == 0 && mp[temp[0]] == 1)
                res.insert(temp);
            return;
        }

        if (temp.size() > 1 && mp[temp[temp.size() - 1]] == 0 && mp[temp[0]] == 1)
            res.insert(temp);

        sol(i + 1, temp + S[i], n, S);
        sol(i + 1, temp, n, S);
    }

    set<string> allPossibleSubsequences(string S)
    {
        int n = S.size();

        for (auto &x : S)
        {
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||
                x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
            {
                mp[x] = 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (mp[S[i]] == 1)
            {
                sol(i, "", n, S);
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
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            for (auto i : ans)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
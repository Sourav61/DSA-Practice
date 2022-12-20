// https://practice.geeksforgeeks.org/problems/queries-on-strings5636/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> SolveQueris(string str, vector<vector<int>> Query)
    {

        vector<int> res;

        for (auto &x : Query)
        {
            vector<int> check(26, 0);
            for (int i = x[0] - 1; i < x[1]; i++)
            {
                check[str[i] - 'a'] = 1;
            }
            int cnt = 0;
            for (auto &y : check)
            {
                if (y == 1)
                {
                    cnt++;
                }
            }

            res.push_back(cnt);
        }

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        int q;
        cin >> q;
        vector<vector<int>> Query;
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            Query.push_back({l, r});
        }
        Solution obj;
        vector<int> ans = obj.SolveQueris(str, Query);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
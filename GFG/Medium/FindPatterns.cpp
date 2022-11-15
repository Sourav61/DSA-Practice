// https://practice.geeksforgeeks.org/problems/find-patterns0606/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int numberOfSubsequences(string S, string W)
    {
        int n = S.length();
        int m = W.length();

        vector<bool> vis(n, false);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (S[i] == W[0] && !vis[i])
            {
                vis[i] = true;
                int j = i + 1;
                int k = 1;

                while (j < n && k < m)
                {
                    if (S[j] == W[k] && !vis[j])
                    {
                        vis[j] = true;
                        k++;
                    }
                    j++;
                }

                if (k == m)
                {
                    res++;
                }
                else
                {
                    break;
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
        string S, W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S, W) << endl;
    }
    return 0;
}

// } Driver Code Ends
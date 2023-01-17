// https://practice.geeksforgeeks.org/problems/longest-string-chain/1?page=1&sortBy=accuracy

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool checkPossible(string &s1, string &s2)
    {
        if (s1.size() != s2.size() + 1)
            return false;

        int first = 0;
        int sec = 0;

        while (first < s1.size())
        {
            if (sec < s2.size() && s1[first] == s2[sec])
            {
                first++;
                sec++;
            }
            else
            {
                first++;
            }
        }

        if (first == s1.size() && sec == s2.size())
            return true;

        return false;
    }

    static bool comp(string &a, string &b)
    {
        return a.size() < b.size();
    }

    int longestChain(int n, vector<string> &words)
    {
        vector<int> dp(n, 1);
        int maxi = 1;

        sort(words.begin(), words.end(), comp);

        for (int i = 1; i < n; i++)
        {
            for (int prev = 0; prev < n; prev++)
            {
                if (checkPossible(words[i], words[prev]) && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                }
            }
            if (dp[i] > maxi)
                maxi = dp[i];
        }

        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++)
        {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends
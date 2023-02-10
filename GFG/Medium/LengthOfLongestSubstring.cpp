// https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestUniqueSubsttr(string S)
    {
        // code
        vector<int> temp(26, -1);
        int n = S.length();
        int res = 0, start = -1;

        for (int i = 0; i < n; i++)
        {
            if (temp[S[i] - 'a'] > start)
            {
                start = temp[S[i] - 'a'];
            }

            temp[S[i] - 'a'] = i;
            res = max(res, i - start);
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
        string str;
        cin >> str;
        Solution ob;
        cout << ob.longestUniqueSubsttr(str) << endl;
    }
    return 0;
}
// } Driver Code Ends

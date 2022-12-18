// https://practice.geeksforgeeks.org/problems/least-prime-factor5216/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> leastPrimeFactor(int n)
    {
        vector<int> seive(n + 1, 0);
        seive[0] = 0;
        seive[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (seive[i] == 0)
            {
                seive[i] = i;
                for (int j = i * i; j <= n; j += i)
                {
                    if (seive[j] == 0)
                        seive[j] = i;
                }
            }
        }

        return seive;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<int> ans = ob.leastPrimeFactor(n);
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
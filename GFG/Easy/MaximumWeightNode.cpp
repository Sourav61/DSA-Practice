// https://practice.geeksforgeeks.org/problems/b64485d3994958cca8748991bb58668204b3e4c0/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int maxWeightCell(int n, vector<int> Edge)
    {
        vector<int> wt(n, 0);

        int maxi = -1, res = 0;

        for (int i = 0; i < n; i++)
        {
            if (Edge[i] != -1)
                wt[Edge[i]] += i;
        }

        for (int i = 0; i < n; i++)
        {
            if (wt[i] >= maxi)
            {
                res = i;
                maxi = wt[i];
            }
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
        int N;
        cin >> N;
        vector<int> Edge(N);
        for (int i = 0; i < N; i++)
        {
            cin >> Edge[i];
        }
        Solution obj;
        int ans = obj.maxWeightCell(N, Edge);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
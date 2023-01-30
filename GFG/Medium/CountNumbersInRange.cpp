// https://practice.geeksforgeeks.org/problems/count-numbers-in-range5305/1

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int count3DivNums(long long L, long long R)
    {
        if (L > R)
        {
            return -1;
        }

        int n = sqrt(R);
        vector<int> seive(n + 1, 0);
        seive[1] = 1;

        for (long long int i = 2; i <= n; i++)
        {
            if (seive[i] == 0)
            {
                for (long long int j = i * i; j <= n; j += i)
                {
                    seive[j] = 1;
                }
            }
        }

        long long int cnt = 0;

        for (long long int i = sqrt(L); i <= n; i++)
        {
            if (seive[i] == 0 && i * i >= L && i * i <= R)
            {
                cnt++;
            }
        }

        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long L, R;

        cin >> L >> R;

        Solution ob;
        cout << ob.count3DivNums(L, R) << endl;
    }
    return 0;
}
// } Driver Code Ends
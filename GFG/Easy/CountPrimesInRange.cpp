// https://practice.geeksforgeeks.org/problems/count-primes-in-range1604/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int countPrimes(int L, int R)
    {
        if (L > R)
        {
            return -1;
        }

        int n = sqrt(R);
        vector<int> seive(R + 1, 0);
        seive[1] = 1;

        for (long long int i = 2; i <= n; i++)
        {
            if (seive[i] == 0)
            {
                for (long long int j = i * i; j <= R; j += i)
                {
                    seive[j] = 1;
                }
            }
        }

        long long int cnt = 0;

        for (long long int i = L; i <= R; i++)
        {
            if (seive[i] == 0 && i >= L && i <= R)
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
        int L, R;
        cin >> L >> R;
        Solution ob;
        int ans = ob.countPrimes(L, R);
        cout << ans << "\n";
    }
}
// } Driver Code Endss
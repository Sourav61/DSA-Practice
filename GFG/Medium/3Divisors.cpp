// https://practice.geeksforgeeks.org/problems/3-divisors3942/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int m = 1000001;

    void seive(vector<int> &arr, vector<int> &primes)
    {
        for (int i = 2; i * i <= m; i++)
        {
            if (arr[i] == 0)
            {
                for (int j = i + i; j <= m; j += i)
                {
                    arr[j] = 1;
                }
            }
        }

        int cnt = 0;

        for (int i = 2; i <= m; i++)
        {
            if (arr[i] == 0)
            {
                cnt++;
            }

            primes[i] = cnt;
        }
    }

    vector<int> threeDivisors(vector<long long> query, int q)
    {
        vector<int> arr(1000001, 0);
        vector<int> primes(1000001, 0);

        vector<int> res;

        seive(arr, primes);

        for (int i = 0; i < q; i++)
        {
            res.push_back(primes[(int)(sqrt(query[i]))]);
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
        int q;
        cin >> q;
        vector<long long> query(q);
        for (int i = 0; i < q; i++)
        {
            cin >> query[i];
        }
        Solution ob;

        vector<int> ans = ob.threeDivisors(query, q);
        for (auto cnt : ans)
        {
            cout << cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
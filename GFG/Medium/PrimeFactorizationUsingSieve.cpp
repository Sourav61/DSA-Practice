// https://practice.geeksforgeeks.org/problems/prime-factorization-using-sieve/1?page=1&sortBy=newest&query=page1sortBynewest

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int sz = 100100;
    vector<int> seives;
    void sieve()
    {
        seives.resize(sz, 0);
        for (int i = 2; i <= sqrt(sz); i++)
        {
            if (seives[i] == 0)
            {
                for (int j = i * i; j <= sz; j += i)
                {
                    seives[j] = 1;
                }
            }
        }
    }

    vector<int> findPrimeFactors(int N)
    {
        vector<int> res;
        if (N == 1)
        {
            return res;
        }

        if (seives[N] == 0)
        {
            res.push_back(N);
            return res;
        }

        for (int i = 2; i <= N; i++)
        {
            if (seives[i] == 0 && N % i == 0)
            {
                while (N % i == 0)
                {
                    res.push_back(i);
                    N /= i;
                }
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
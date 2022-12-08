// https://practice.geeksforgeeks.org/problems/nine-divisors3751/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int nineDivisors(long long int N)
    {
        long long int ans = 0;
        int size = (int)sqrt(N);
        vector<int> prime(size + 1);

        for (int i = 1; i <= size; i++)
        {
            prime[i] = i;
        }

        for (int i = 2; i * i <= size; i++)
        {
            if (prime[i] == i)
            {
                for (int j = i + i; j <= size; j += i)
                {
                    if (prime[j] == j)
                    {
                        prime[j] = i;
                    }
                }
            }
        }

        for (int i = 2; i <= size; i++)
        {
            int p = prime[i];
            int q = prime[i / p];

            if ((p != q && p * q == i && q != 1) ||
                (prime[i] == i && pow(i, 8) <= N))
            {
                ans += 1;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int N;
        cin >> N;
        Solution ob;
        cout << ob.nineDivisors(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
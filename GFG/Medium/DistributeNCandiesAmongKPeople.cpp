// https://practice.geeksforgeeks.org/problems/distribute-n-candies/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<long long> distributeCandies(int N, int K)
    {
        // code here
        vector<long long> res(K, 0);
        int i = 0;

        while (true)
        {

            if (N < (((i / K) * K) + (i % K) + 1))
            {
                res[i % K] += N;
                break;
            }

            N -= (((i / K) * K) + (i % K) + 1);
            res[i % K] += (((i / K) * K) + (i % K)) + 1;
            i++;
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
        int N, K;
        cin >> N >> K;

        Solution ob;
        vector<long long> res = ob.distributeCandies(N, K);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
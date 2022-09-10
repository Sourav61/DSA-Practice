// https://practice.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long kSmallest(long long A[], long long k)
    {
        priority_queue<int, vector<int>, greater<int>> minH;

        for (auto x : A)
            minH.push(x);

        while (k--)
        {
            minH.pop();
        }

        return minH.top();
    };

    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
    {
        int sum = 0;
        int first = kSmallest(A, k1);
        int second = kSmallest(A, k2);

        for (auto x : A)
        {
            if (x > first && x < second)
            {
                sum += x
            }
        }

        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n;
        long long a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
    }
    return 0;
}

// } Driver Code Ends
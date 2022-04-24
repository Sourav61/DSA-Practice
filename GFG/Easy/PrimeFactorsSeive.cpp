// https://practice.geeksforgeeks.org/problems/prime-factors5052/1/#

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> AllPrimeFactors(int n)
    {
        vector<int> v;
        set<int> s;
        if (n == 2)
        {
            s.insert(n);
        }
        for (int i = 2; i <= n; i++)
        {
            while (n % i == 0)
            {
                s.insert(i);
                n /= i;
            }
        }

        for (auto it : s)
        {
            v.push_back(it);
        }
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long int N;
        cin >> N;
        Solution ob;
        vector<int> ans = ob.AllPrimeFactors(N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends
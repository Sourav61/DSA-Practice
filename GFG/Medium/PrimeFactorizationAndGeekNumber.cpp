// https://practice.geeksforgeeks.org/problems/prime-factorization-and-geek-number1915/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int geekNumber(int N)
    {
        if (N % 2 == 0)
        {
            N /= 2;
            if (N % 2 == 0)
            {
                return false;
            }
        }

        for (int i = 3; i <= sqrt(N); i += 2)
        {
            if (N % i == 0)
            {
                N /= i;
                if (N % i == 0)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        if (ob.geekNumber(N))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/help-ishaan5837/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int NthTerm(int N)
    {
        // Code here
        int low = N, high = N + 1;

        while (!prime(low))
            low--;
        while (!prime(high))
            high++;

        return min(N - low, high - N);
    }

    bool prime(int n)
    {
        if (n == 0 or n == 1)
            return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
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
        Solution obj;
        int ans = obj.NthTerm(N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
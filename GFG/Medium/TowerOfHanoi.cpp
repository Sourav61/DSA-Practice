// https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1/#

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int n, int src, int dest, int helper)
    {
        long long count = 0;
        if (n == 0 || n < 0)
        {
            return 0;
        }
        if (n > 0)
        {
            count += toh(n - 1, src, helper, dest);
            cout << "move disk " << n << " from rod " << src << " to rod " << dest << endl;
            count += toh(n - 1, helper, dest, src);
        }
        return count + 1;
    }
};

// { Driver Code Starts.

int main()
{

    int T;
    cin >> T; // testcases
    while (T--)
    {

        int N;
        cin >> N; // taking input N

        // calling toh() function
        Solution ob;

        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}

// Position this line where user code will be pasted.  // } Driver Code Ends
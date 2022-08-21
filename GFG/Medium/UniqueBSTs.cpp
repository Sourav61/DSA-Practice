// https://practice.geeksforgeeks.org/problems/unique-bsts-1587115621/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return the total number of possible unique BST.
    int numTrees(int N)
    {
        if (n <= 1)
            return 1;

        int res = 0;
        for (int i = 0; i <= n - 1; i++)
        {
            res += numTrees(i) * numTrees(n - i - 1);
        }

        return res;
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9 + 7)
int main()
{

    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {

        // taking total number of elements
        int n;
        cin >> n;
        Solution ob;
        // calling function numTrees()
        cout << ob.numTrees(n) << "\n";
    }
}
// } Driver Code Ends
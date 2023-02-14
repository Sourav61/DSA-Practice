// https://practice.geeksforgeeks.org/problems/stack-permutations/1?page=2&category[]=Stack&sortBy=difficulty

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isStackPermutation(int N, vector<int> &A, vector<int> &B)
    {
        stack<int> st;
        int n = A.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            st.push(A[i]);

            while (!st.empty() && st.top() == B[j])
            {
                st.pop();
                j++;
            }
        }

        if (!st.empty())
        {
            return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.isStackPermutation(n, a, b) << endl;
    }

    return 0;
}
// } Driver Code Ends
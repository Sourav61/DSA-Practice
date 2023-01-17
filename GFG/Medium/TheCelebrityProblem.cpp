// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }

        while (st.size() > 1)
        {
            int p1 = st.top();
            st.pop();

            int p2 = st.top();
            st.pop();

            if (M[p1][p2] == 1)
            {
                st.push(p2);
            }
            else
            {
                st.push(p1);
            }
        }

        int celeb = st.top();

        for (int i = 0; i < n; i++)
        {
            if (celeb == i)
            {
                continue;
            }
            if (M[celeb][i] == 1)
            {
                return -1;
            }

            if (M[i][celeb] == 0)
            {
                return -1;
            }
        }

        return celeb;
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
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}

// } Driver Code Ends
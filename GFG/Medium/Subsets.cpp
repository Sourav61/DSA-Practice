// https://practice.geeksforgeeks.org/problems/subsets-1613027340/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void findCombi(int ind, vector<int> &A, vector<int> &ds, vector<vector<int>> &ans)
    {
        ans.push_back(ds);

        for (int i = ind; i < A.size(); i++)
        {
            if (i == A.size())
                break;
            ds.push_back(A[i]);
            findCombi(i + 1, A, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &A)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        findCombi(0, A, ds, ans);
        sort(ans.begin(), ans.end());
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
        int n, x;
        cin >> n;

        vector<int> array;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            array.push_back(x);
        }

        Solution ob;
        vector<vector<int>> res = ob.subsets(array);

        // Print result
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
// } Driver Code Ends
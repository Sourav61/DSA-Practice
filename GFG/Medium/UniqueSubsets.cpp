// https://practice.geeksforgeeks.org/problems/subsets-1587115621/1/#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find all possible unique subsets.
    vector<vector<int>> AllSubsets(vector<int> arr, int n)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    temp.push_back(arr[j]);
                }
            }
            ans.push_back(temp);
            temp.clear();
        }

        for (int i = 0; i < ans.size(); i++)
        {
            sort(ans[i].begin(), ans[i].end());
        }

        set<vector<int>> s;

        for (int i = 0; i < ans.size(); i++)
        {
            s.insert(ans[i]);
        }

        ans.clear();

        for (auto it : s)
        {
            ans.push_back(it);
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int>> result = obj.AllSubsets(A, n);
        // printing the output
        for (int i = 0; i < result.size(); i++)
        {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> constructList(vector<vector<int>> Q, int N)
    {
        vector<int> res;
        int x = 0;

        for (int i = N - 1; i >= 0; i--)
        {
            if (Q[i][0] == 0)
            {
                res.push_back(Q[i][1] ^ x);
            }
            else
            {
                x = x ^ Q[i][1];
            }
        }
        res.push_back(0 ^ x);
        sort(res.begin(), res.end());

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, type, val;
        cin >> N;

        vector<vector<int>> Q;

        for (int i = 0; i < N; i++)
        {
            cin >> type >> val;
            vector<int> temp;
            temp.push_back(type);
            temp.push_back(val);
            Q.push_back(temp);
        }

        Solution ob;
        vector<int> res = ob.constructList(Q, N);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
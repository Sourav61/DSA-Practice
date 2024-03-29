// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> minPartition(int N)
    {
        vector<int> arr = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

        vector<int> temp;

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < (x / arr[i]); j++)
            {
                temp.push_back(arr[i]);
            }
            x -= (x / arr[i]) * arr[i];
        }

        return temp;
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
        vector<int> numbers = ob.minPartition(N);
        for (auto u : numbers)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
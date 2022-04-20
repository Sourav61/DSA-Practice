// https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1/?page=1&status[]=unsolved&category[]=Bit%20Magic&sortBy=submissions#

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int MissingNumber(vector<int> &array, int n)
    {
        int asum = 0;
        for (int i = 0; i < array.size(); i++)
        {
            asum += array[i];
        }

        int sum = n * (n + 1) / 2;

        return sum - asum;
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

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends
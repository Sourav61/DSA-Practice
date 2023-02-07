// https://practice.geeksforgeeks.org/problems/4dfa8ba14d4c94f4d7637b6b5246782412f3aeb8/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to return the length of the
    // longest subarray with ppositive product
    int maxLength(vector<int> &arr, int n)
    {
        int posLen = 0, negLen = 0, res = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                posLen = 0, negLen = 0;
            }
            else if (arr[i] > 0)
            {
                posLen++;
                if (negLen != 0)
                {
                    negLen++;
                }
            }
            else
            {
                swap(posLen, negLen);
                negLen++;
                if (posLen != 0)
                {
                    posLen++;
                }
            }

            res = max(res, posLen);
        }

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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        int res = ob.maxLength(arr, n);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends
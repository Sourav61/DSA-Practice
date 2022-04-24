// https://practice.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1/#

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool getBit(int n, int pos)
    {
        return ((n & (1 << pos)) != 0);
    }

    int setBit(int n, int pos)
    {
        return (n | (1 << pos));
    }
    int singleElement(int arr[], int n)
    {
        int result = 0;

        for (int i = 0; i < 64; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (getBit(arr[j], i))
                {
                    sum++;
                }
            }

            if (sum % 3 != 0)
            {
                result = setBit(result, i);
            }
        }

        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;
        int arr[N];

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.singleElement(arr, N);
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1/?page=1&difficulty[]=1&status[]=unsolved&category[]=Arrays&category[]=Recursion&sortBy=submissions
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        // if (size == 1)
        //     return a[0];
        // int ans = -1;
        // int count = 0;
        // for (int i = 0; i < size; i++)
        // {
        //     if (count == 0)
        //     {
        //         ans = a[i];
        //         count = 1;
        //     }
        //     else
        //     {
        //         if (a[i] == ans)
        //             count++;
        //         else
        //             count--;
        //     }
        // }
        // count = 0;
        // for (int i = 0; i < size; i++)
        // {
        //     if (a[i] == ans)
        //         count++;
        // }
        // if (count > size / 2)
        //     return ans;
        // else
        //     return -1;

        int x = size / 2;
        unordered_map<int, int> m;
        for (int i = 0; i < size; i++)
            m[a[i]]++;
        int res = -1;
        for (int i = 0; i < size; i++)
        {
            if (m[a[i]] > x)
            {
                res = a[i];
                break;
            }
        }
        return res;
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
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
// } Driver Code Ends
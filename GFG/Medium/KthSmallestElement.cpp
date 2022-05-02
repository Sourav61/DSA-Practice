// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1/?page=1&difficulty[]=1&status[]=unsolved&category[]=Arrays&category[]=Recursion&sortBy=submissions#
// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        vector<int> v;

        for (int i = 0; i <= r; i++)
        {
            v.push_back(arr[i]);
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++)
        {
            if (i == k - 1)
            {
                return v[i];
            }
        }

        return 2147483647;
    }
};

// { Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
            cin >> a[i];

        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(a, 0, number_of_elements - 1, k) << endl;
    }
    return 0;
} // } Driver Code Endss
// https://practice.geeksforgeeks.org/problems/duplicate-elements/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    void SortedDuplicates(int n, vector<int> &arr)
    {
        set<int> ans;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                ans.insert(arr[i]);
            }
        }
        if (ans.size() == 0)
        {
            ans.insert(-1);
        }

        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;

        obj.SortedDuplicates(n, arr);
    }
}

// } Driver Code Ends
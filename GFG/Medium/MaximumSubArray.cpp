// https://practice.geeksforgeeks.org/problems/maximum-sub-array5443/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> findSubarray(int a[], int n)
    {
        long long s = 0, start = 0, end = 0, maxi = INT_MIN, sum = 0;

        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            if (a[i] >= 0)
            {
                sum += a[i];
                if (sum >= maxi)
                {
                    maxi = sum;
                    start = s;
                    end = i;
                }
            }
            else
            {
                sum = 0;
                s = i + 1;
            }
        }
        if (start == end && a[start] < 0)
            return {-1};

        for (int j = start; j <= end; j++)
            v.push_back(a[j]);

        return v;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans)
{
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends
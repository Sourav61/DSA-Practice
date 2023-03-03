// https://practice.geeksforgeeks.org/problems/min-sum-formed-by-digits3551/1?page=1&category[]=Queue&sortBy=difficulty

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int minSum(int arr[], int n)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }

        long long int num1 = 0, num2 = 0;

        while (!pq.empty())
        {
            auto first = pq.top();
            pq.pop();
            int second = -1;
            if (!pq.empty())
            {
                second = pq.top();
                pq.pop();
            }

            num1 = num1 * 10 + first;
            if (second != -1)
                num2 = num2 * 10 + second;
        }

        // cout<<num1<<" "<<num2<<endl;

        return num2 + num1;
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
        int arr[n + 1];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.minSum(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
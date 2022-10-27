// https://practice.geeksforgeeks.org/problems/minimum-sum-of-subarray/0

#include <bits/stdc++.h>
using namespace std;

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
            cin >> arr[i];

        for (int j = 0; j < n; j++)
        {
            int mini = INT_MAX;
            int curr = 0;

            for (int i = j; i < n; i++)
            {
                curr = min(arr[i], arr[i] + curr);
                mini = min(curr, mini);
            }
            cout << mini << " ";
        }
        cout << endl;
    }

    return 0;
}
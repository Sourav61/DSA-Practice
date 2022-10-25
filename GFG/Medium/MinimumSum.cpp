// https://practice.geeksforgeeks.org/problems/minimum-sum4058/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string sumString(string s1, string s2)
    {
        int i = s1.length() - 1;
        int j = s2.length() - 1;

        string sum = "";

        int carry = 0;

        while (i >= 0 && j >= 0)
        {
            int d1 = s1[i] - '0';
            int d2 = s2[j] - '0';

            sum = to_string((d1 + d2 + carry) % 10) + sum;
            carry = (d1 + d2 + carry) / 10;

            i--, j--;
        }

        while (i >= 0)
        {
            int d1 = s1[i] - '0';
            sum = to_string((d1 + carry) % 10) + sum;
            carry = (d1 + carry) / 10;
            i--;
        }

        while (j >= 0)
        {
            int d2 = s2[j] - '0';
            sum = to_string((d2 + carry) % 10) + sum;
            carry = (d2 + carry) / 10;
            j--;
        }

        if (carry != 0)
        {
            sum = to_string(carry) + sum;
        }

        for (int i = 0; i < sum.size(); i++)
        {
            if (sum[i] != '0')
            {
                return sum.substr(i);
            }
        }

        return "0";
    }

    string solve(int arr[], int n)
    {
        sort(arr, arr + n);

        string num1 = "", num2 = "";

        for (int i = 0; i < n; i++)
        {
            if ((i % 2) == 0)
            {
                num1 += to_string(arr[i]);
            }
            else
            {
                num2 += to_string(arr[i]);
            }
        }

        return sumString(num1, num2);
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
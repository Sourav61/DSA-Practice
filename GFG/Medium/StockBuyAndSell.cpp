// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell2615/1

//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++)
            cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends

// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n)
{
    vector<vector<int>> res;
    int st, end;
    int flag = 1;

    for (int i = 0; i < n - 1; i++)
    {
        if (flag)
        {
            if (price[i] < price[i + 1])
            {
                flag = 0;
                st = i;
            }
        }
        else
        {
            if (price[i] > price[i + 1])
            {
                flag = 1;
                end = i;
                res.push_back({st, end});
            }
        }
    }

    if (flag == 0)
    {
        res.push_back({st, n - 1});
    }

    if (res.size() == 0)
    {
        cout << "No Profit" << endl;
        return;
    }

    for (auto &x : res)
    {
        cout << "(" << x[0] << " " << x[1] << ")"
             << " ";
    }
    cout << endl;
}
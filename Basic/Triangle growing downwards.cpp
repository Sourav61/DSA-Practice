// https://practice.geeksforgeeks.org/problems/triangle-growing-downwards2344/1/?page=1&difficulty[]=-1&status[]=unsolved&category[]=Design-Pattern&category[]=pattern-printing&sortBy=submissions#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printTriangleDownwards(string str)
    {
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                cout << ".";
            }
            for (int j = 0; j < i + 1; j++)
            {
                cout << str[j];
            }
            cout << endl;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        ob.printTriangleDownwards(str);
    }
    return 0;
} // } Driver Code Ends
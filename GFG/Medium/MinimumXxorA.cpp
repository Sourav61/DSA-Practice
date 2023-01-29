// https://practice.geeksforgeeks.org/problems/1fc4278adf2a36780f637c7b4cd06391dd1487e4/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int setBits(int n)
    {
        int cnt = 0;

        while (n > 0)
        {
            if ((n & 1) != 0)
            {
                cnt++;
            }

            n /= 2;
        }

        return cnt;
    }

    int minVal(int a, int b)
    {
        int sb1 = setBits(a);
        int sb2 = setBits(b);

        if (sb1 == sb2)
        {
            return a;
        }

        int res = 0;

        for (int i = 0; i < 32; i++)
        {
            int mask = 1 << i;
            int setBit = a & mask;

            if (setBit == 0 && sb1 < sb2)
            {
                res = res | mask;
                sb2--;
            }
            else if (setBit != 0 && sb1 > sb2)
            {
                sb1--;
            }
            else
            {
                res = res | setBit;
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
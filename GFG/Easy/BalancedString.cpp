// https://practice.geeksforgeeks.org/problems/balanced-string1627/1

//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution
{
public:
    string BalancedString(int N)
    {
        string ans;

        string allCh;

        for (int i = 0; i < 26; i++)
        {
            allCh += (char)('a' + i);
        }

        int allChTimes = N / 26;
        int r = N % 26;

        while (allChTimes-- > 0)
        {
            ans += allCh;
        }

        if (N % 2 == 0)
        {
            for (int i = 0; i < r / 2; i++)
                ans += (char)('a' + i);

            for (int i = 26 - r / 2; i < 26; i++)
            {
                ans += (char)('a' + i);
            }
        }
        else
        {
            int sod = 0, t = N;

            while (t > 0)
            {
                sod += t % 10;
                t /= 10;
            }
            if (sod % 2 == 0)
            {
                for (int i = 0; i < (r + 1) / 2; i++)
                {
                    ans += (char)('a' + i);
                }
                for (int i = 26 - ((r - 1) / 2); i < 26; i++)
                {
                    ans += (char)('a' + i);
                }
            }
            else
            {
                for (int i = 0; i < (r - 1) / 2; i++)
                {
                    ans += (char)('a' + i);
                }
                for (int i = 26 - ((r + 1) / 2); i < 26; i++)
                {
                    ans += (char)('a' + i);
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends
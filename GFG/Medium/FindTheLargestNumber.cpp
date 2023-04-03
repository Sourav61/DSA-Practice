// https://practice.geeksforgeeks.org/problems/find-the-largest-number4953/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool check(int n)
    {
        string s = to_string(n);

        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] > s[i])
            {
                return false;
            }
        }

        return true;
    }

    int find(int N)
    {
        while (N)
        {
            if (check(N))
            {
                return N;
            }
            else
            {
                N--;
            }
        }

        return -1;
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
        cout << ob.find(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/c-corresponding-position-in-the-two-strings-that-hold-exactly-the-same-characters5013/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int sameChar(string A, string B)
    {
        int cnt = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < A.length(); i++)
        {
            if ((int)(A[i]) >= 97)
            {
                mp[i] = (int)A[i] - 97;
            }
            else
            {
                mp[i] = (int)A[i] - 65;
            }
        }

        for (int i = 0; i < B.length(); i++)
        {
            if ((int)(B[i]) >= 97)
            {
                if ((int)(B[i]) - 97 == mp[i])
                {
                    cnt++;
                }
            }
            else
            {
                if ((int)(B[i]) - 65 == mp[i])
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A;
        cin >> B;
        Solution ob;
        cout << ob.sameChar(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends
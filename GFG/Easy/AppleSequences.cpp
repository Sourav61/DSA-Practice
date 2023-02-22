// https://practice.geeksforgeeks.org/problems/38f100615d0b2efa755e7b07f905e0f8cd2fe5df/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int appleSequences(int n, int m, string arr)
    {
        int st = 0, count = 0, maxi = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 'A')
            {
                maxi = max(maxi, i - st + 1);
            }
            else
            {
                count++;

                if (count > m)
                {
                    while (st < i && arr[st] == 'A')
                    {
                        st++;
                    }

                    st++;
                }

                maxi = max(maxi, i - st + 1);
            }
        }

        return maxi;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;

        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
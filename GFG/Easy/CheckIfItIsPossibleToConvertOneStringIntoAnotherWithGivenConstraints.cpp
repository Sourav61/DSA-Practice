// https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-convert-one-string-into-another-with-given-constraints4116/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isItPossible(string S, string T, int M, int N)
    {
        if (M != N)
        {
            return 0;
        }

        int a = 0;
        int b = 0;

        for (int i = 0; i < N; i++)
        {
            if (S[i] == 'A')
            {
                a++;
            }
            else if (S[i] == 'B')
            {
                b++;
            }

            if (T[i] == 'A')
            {
                a--;
            }
            else if (T[i] == 'B')
            {
                b--;
            }
        }

        if (a != 0 || b != 0)
        {
            return 0;
        }

        int i = 0;
        int j = 0;

        while (i < N && j < N)
        {
            while (i < N && S[i] == '#')
                i++;
            while (j < N && T[j] == '#')
                j++;

            if (i == N || j == N)
                break;

            if (S[i] == 'A')
            {
                if (T[j] == 'A')
                {
                    if (j > i)
                        return 0;
                    else
                    {
                        i++;
                        j++;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if (T[j] == 'B')
                {
                    if (j < i)
                        return 0;
                    else
                    {
                        i++;
                        j++;
                    }
                }
                else
                {
                    return 0;
                }
            }
        }

        return 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends
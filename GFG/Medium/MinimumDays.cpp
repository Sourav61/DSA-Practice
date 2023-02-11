// https://practice.geeksforgeeks.org/problems/f4d22b1f9d62e8bee0ff84e9fa51dc66eb5005ec/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends
class Solution
{
public:
    int getMinimumDays(int N, string S, vector<int> &P)
    {
        // unordered_map<int,int> mp;

        int sum = 0, flag = 0;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == S[i + 1])
            {
                flag = 1;
                sum++;
            }
        }

        if (flag == 0)
            return 0;

        int m = P.size();

        int i = 0, res = 0;
        while (i < m && sum > 0)
        {
            int x = P[i];
            if (S[x] == S[x + 1] && S[x] == S[x - 1])
            {
                S[x] = '?';
                sum -= 2;
            }
            else if (S[x] == S[x + 1] || S[x] == S[x - 1])
            {
                S[x] = '?';
                sum--;
            }
            i++;
            res++;
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);
        string S;
        cin >> S;

        vector<int> P(N);
        Array::input(P, N);

        Solution obj;
        int res = obj.getMinimumDays(N, S, P);

        cout << res << endl;
    }
}

// } Driver Code Ends
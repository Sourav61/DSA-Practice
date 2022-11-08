// https://practice.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)
    {
        int x = 0;

        for (int i = 0; i < N; i++)
        {
            x ^= Arr[i];
        }

        int set = x & ~(x - 1);

        long long int f = 0;
        long long int s = 0;

        for (int i = 0; i < N; i++)
        {
            if (set & Arr[i])
            {
                f ^= Arr[i];
            }
            else
            {
                s ^= Arr[i];
            }
        }

        if (f >= s)
        {
            return {f, s};
        }

        return {s, f};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int N;
        cin >> N;
        long long int Arr[N];
        for (long int i = 0; i < N; i++)
            cin >> Arr[i];
        Solution ob;
        vector<long long int> ans = ob.twoOddNum(Arr, N);
        for (long long int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
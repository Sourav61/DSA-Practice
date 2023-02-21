// https://practice.geeksforgeeks.org/problems/202d95ecdeec659401edc63dd952b1d37b989ab8/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long solve(int n, int k, vector<long long> arr)
    {
        // code her
        long sum = 0;

        vector<long> temp;

        for (auto &x : arr)
        {
            sum += x;
            temp.push_back(x);
        }

        int st = 0;

        while (temp.size() < n)
        {
            temp.push_back(sum);

            sum += sum;
            sum -= temp[st];
            st++;
        }

        return temp[n - 1];
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++)
            cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends
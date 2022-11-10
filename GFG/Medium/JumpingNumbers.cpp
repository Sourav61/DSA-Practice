// https://practice.geeksforgeeks.org/problems/jumping-numbers3805/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maxi = INT_MIN;

    long long jumpingNums(long long X)
    {
        queue<int> q;

        for (int i = 0; i <= 9; i++)
        {
            q.push(i);
        }

        while (!q.empty())
        {
            int num = q.front();
            q.pop();

            if (num <= X)
            {
                maxi = max(num, maxi);
                int last_dig = num % 10;

                if (last_dig == 0)
                {
                    q.push((num * 10) + (last_dig + 1));
                }
                else if (last_dig == 9)
                {
                    q.push((num * 10) + (last_dig - 1));
                }
                else
                {
                    q.push((num * 10) + (last_dig + 1));
                    q.push((num * 10) + (last_dig - 1));
                }
            }
        }

        return maxi;
    };
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long X;

        cin >> X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends

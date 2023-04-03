// https://practice.geeksforgeeks.org/problems/839d6ba2c2e4c669ba9d9d9f32ad20118937284e/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int countSubstring(string S)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0, sum = 0;

        for (auto &x : S)
        {
            int temp;

            if ((int)x >= 97 && (int)x <= 122)
            {
                temp = 1;
            }
            else
            {
                temp = -1;
            }

            sum += temp;

            if (mp.find(sum) != mp.end())
            {
                res += mp[sum];
            }

            mp[sum]++;
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
        string S;
        cin >> S;
        Solution obj;
        cout << obj.countSubstring(S) << endl;
    }
}
// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1?problemStatus=unsolved&page=1&sortBy=newest&query=problemStatusunsolvedpage1sortBynewest

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int totalFruits(int N, vector<int> &fruits)
    {
        int n = fruits.size(), j = 0, res = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[fruits[i]]++;

            while (mp.size() > 2 && j <= i)
            {
                mp[fruits[j]]--;
                if (mp[fruits[j]] == 0)
                {
                    mp.erase(fruits[j]);
                }
                j++;
            }

            res = max(res, i - j + 1);
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
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++)
            cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends